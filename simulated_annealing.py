from __future__ import print_function
import math
import random
from collections import defaultdict
from simanneal import Annealer
import subprocess
import time
from find_max_vals import FindMaxValues

class FindOptimizedConfiguration(Annealer):


	def __init__(self, state):
		self.max_vals = defaultdict(list)
		self.max_vals[16] = [2, 11, 1, 11, 63, 8]
		self.findm = FindMaxValues([32, 32, 32, 32, 32, 32, 32, 1024, 64])
		super(FindOptimizedConfiguration, self).__init__(state)

	def move(self):
		"""Change to neighboring configuration state"""
		
		initial_energy = self.energy()

		# Issue Width, MemLoads, MemSt, MemPft, ALU, MUL, MEMUNITS, Regs, CondRegs
		rand_ind = random.randint(0, 8)

		new_states = [random.randint(2, 32), random.randint(1, 32), random.randint(1, 32), random.randint(1, 32), random.randint(2, 32), random.randint(1, 32), random.randint(1, 32), random.randint(32, 1024), random.randint(8, 64)]
			
		self.state[rand_ind] = new_states[rand_ind]
		if rand_ind == 0 :
			if len(self.max_vals[new_states[0]]) == 0 :
				self.findm.set_width(new_states[0])
				indices = [1, 2, 3, 6, 7, 8]
				mins = [self.findm.fm(x) for x in indices]	
				for x in indices : 
					self.max_vals[new_states[0]].append(x)
				
		self.state[1] = random.randint(1, self.max_vals[self.state[0]][0])
		self.state[2] = random.randint(1, self.max_vals[self.state[0]][1])
		self.state[3] = random.randint(1, self.max_vals[self.state[0]][2])
		self.state[6] = random.randint(1, self.max_vals[self.state[0]][3])
		self.state[7] = random.randint(32, self.max_vals[self.state[0]][4])
		self.state[8] = random.randint(8, self.max_vals[self.state[0]][5])
		if self.state[4] > self.state[0]:
			self.state[4] = random.randint(2, self.state[0])
		if self.state[5] > self.state[0]:
			self.state[5] = random.randint(1, self.state[0])

		return self.energy() - initial_energy

	def energy(self):
		e = 0
		with open('configuration.mm', 'w') as f:
			f.write("RES: IssueWidth " + str(self.state[0]) + "\n")	
			f.write("RES: MemLoad " + str(self.state[1]) + "\n")	
			f.write("RES: MemStore " + str(self.state[2]) + "\n")	
			f.write("RES: MemPft " + str(self.state[3]) + "\n")	

			f.write("#***Clusters*** 1\n")

			f.write("RES: IssueWidth.0 32 \n")

			f.write("RES: Alu.0 " + str(self.state[4]) + "\n")	
			f.write("RES: Mpy.0 " + str(self.state[5]) + "\n")	
			f.write("RES: Memory.0 " + str(self.state[6]) + "\n")	

			f.write("RES: CopySrc.0 0 \n")
			f.write("RES: CopyDst.0 0 \n")

			f.write("REG: $r0 " + str(self.state[7]) + "\n")	
			f.write("REG: $b0 " + str(self.state[8]) + "\n")	
				
			f.write("DEL: AluR.0 0 \nDEL: Alu.0 0\nDEL: CmpBr.0 0\nDEL: CmpGr.0 0\nDEL: Select.0 0\nDEL: Multiply.0 1\nDEL: Load.0 1\nDEL: LoadLr.0 1\nDEL: Store.0 0\nDEL: Pft.0 0\nDEL: CpGrBr.0 0\nDEL: CpBrGr.0 0\nDEL: CpGrLr.0 0\nDEL: CpLrGr.0 0\nDEL: Spill.0 0\nDEL: Restore.0 1\nDEL: RestoreLr.0 1\nCFG: Quit 0\nCFG: Warn 0\nCFG: Debug 0"
)

		process = subprocess.Popen("run convolution_7x7 -O4", stdout=subprocess.PIPE, shell=True, executable="/bin/bash")
		process.communicate()
		exec_cycles = 0
		with open("output-convolution_7x7.c/ta.log.000", 'r') as f:
			for i, line in enumerate(f):
				if i == 1:
					words = line.split()				
					exec_cycles = float(words[-3])
					break

		area = self.state[4] * 3273 + self.state[5] * 40614 + self.state[1] * 1500 + self.state[2] * 1500 + ((26388/64) * self.state[7] * (self.state[0] / 4) ** 2) + ((258/8) * self.state[8] * (self.state[0] / 4)**2) + (self.state[1] + self.state[2] + self.state[3]) * 1000
	
		norm_exec_cycles = ((exec_cycles - 56522.98) / (28749792 - 56522.98)) * 100
		norm_area = ((area - 56522.98) / (28749792 - 56522.98)) * 100
		norm_product = (1.5 * norm_exec_cycles) * norm_area

		return norm_product


if __name__ == '__main__':
	
	#if we rerun it maybe we want a different initial state
	init_state = [16, 16, 16, 16, 16, 16, 16, 512, 32]
	
	ca = FindOptimizedConfiguration(init_state)
#	ca.set_schedule(ca.auto(minutes=0.2, steps=1))
	ca.set_schedule({"updates":1, "tmax":25000, "tmin":2.5, "steps":1})
	ca.copy_strategy = "slice"
	state, e = ca.anneal()

	area = state[4] * 3273 + state[5] * 40614 + state[1] * 1500 + state[2] * 1500 + ((26388/64) * state[7] * (state[0] / 4) ** 2) + ((258/8) * state[8] * (state[0] / 4)**2) + (state[1] + state[2] + state[3]) * 1000
	norm_area = ((area - 56522.98) / (28749792 - 56522.98)) * 100
	exec_cycles = ((e / norm_area) / 150) * (28749792 - 56522.98) + 56522.98

	print(state)
	print("Energy : " + str(e) + " area : " + str(area) + " exec_cycles : " + str(exec_cycles))

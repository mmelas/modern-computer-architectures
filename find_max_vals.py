from __future__ import print_function
import math
import random
from collections import defaultdict
import subprocess
import time

class FindMaxValues():

	mins = []
	def __init__(self, state):
		self.state = state

	def fm(self, curr_state):
		"""Change to neighboring configuration state"""
		res = 0

		if curr_state == 1:
			res = self.bs(curr_state, 1, 32) 
		if curr_state == 2:
			res = self.bs(curr_state, 1, 32)
		if curr_state == 3:
			res = self.bs(curr_state, 1, 32) 
		if curr_state == 6:
			res = self.bs(curr_state, 1, 32)
		if curr_state == 7:
			res = self.bs(curr_state, 32, 1024)
		if curr_state == 8:
			res = self.bs(curr_state, 8, 64)
				
		return res

	def bs(self, curr_state, left, right):
		left = left
		max_v = right
		self.state[curr_state] = right
		target = self.get_exec_cycles()
			
		while left <= right:
			mid = left + (right - left) // 2
			self.state[curr_state] = mid	
			cycles = self.get_exec_cycles()
			if (cycles <= target) :
				right = mid - 1
			else :
				left = mid + 1

		self.state[curr_state] = max_v
		return left 

	def get_exec_cycles(self):
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


		return exec_cycles

	def set_width(self, width):
		self.state[0] = width


if __name__ == '__main__':
	
	print("HI")
	#if we rerun it maybe we want a different initial state
#	init_state = [16, 32, 32, 32, 32, 32, 32, 1024, 64]
#	findm = FindMaxValues(init_state)
#
#	indices = [1, 2, 3, 6, 7, 8]
#	mins = [findm.fm(x) for x in indices]
#
#	print(" ".join(str(mins[x]) for x in range(0, 6)))

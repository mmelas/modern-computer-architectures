import matplotlib.pyplot as plt
import numpy as np

if __name__ == "__main__":

    plt.figure()
    with open("results.txt", 'r') as f:
        lines = f.readlines()
        x = []
        y = []
        for line in lines:
            state = "["
            state += line[line.find("[")+1:line.find("]")]
            state += "]"
#            if float(line.split()[-9]) > 4000000:
#                print line.split()[-9]
#                print (line.split()[-6][1:-1])
            #one_best_point =5221 on [-5][:-1], second_one=14385(on [-6][1:-1])
            if float(line.split()[-6][1:-1]) == 719220:
                plt.plot([float(line.split()[-9])], [float(line.split()[-6][1:-1])], color = 'red', label = state, marker = 'o', markersize = 5, linewidth = 0)
            x.append(float(line.split()[-9]))
            y.append(float(line.split()[-6][1:-1]))
            #find_best_point_in_grayscale
#            if float(line.split()[-9]) < 550000 and float(line.split()[-6][1:-1]) < 730000: 
#                print("HI")
#                print(line.split()[-6][1:-1])
#                print line.split("[")[1]
            
    plt.scatter(x, y, marker = 'o')
    #convolution plot
    plt.plot([56523, 56523], [483061, max(y)+max(y)*0.1], color="orange", label="baseline")
    plt.plot([56523, max(x)+max(x)*0.1], [483061, 483061], color="green", label="roofline")
    #grayscale plot
#    plt.plot([56523, 56523], [4952, max(y)+max(y)*0.1], color="orange", label="baseline")
#    plt.plot([56523, max(x)+max(x)*0.1], [4952, 4952], color="green", label="roofline")
    plt.legend(loc="best", fontsize = 'x-small', numpoints = 1)
    plt.xlabel("Area")
    plt.ylabel("Execution Cycles")
    plt.xlim(0, max(x) + max(x)*0.1)
    plt.ylim(0, max(y) + max(y)*0.1)
#    plt.show()
    plt.tight_layout()
    plt.savefig('convolution_plot.png', dpi=200)

#    plt.close()

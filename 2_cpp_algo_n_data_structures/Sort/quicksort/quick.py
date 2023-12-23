import matplotlib.pyplot as plt
import numpy as np
my_file = open("quicksort.txt", "r")
content = my_file.read()
content_list = content.split("\n")
content_list.pop()
my_file.close()
N = []
for i in range(1000, 100000, 500):
    N.append(i)
for i in range(len(content_list)):
    content_list[i] = int(content_list[i]) / N[i]
fig = plt.figure()
ax = fig.add_subplot(111)
ax.set_xlabel('N')
ax.set_ylabel('t')
ax.axes.yaxis.set_ticks([])
ax.set_title('log(N)')
ax.plot(N, content_list, '.k')

plt.show()

import matplotlib.pyplot as plt

# 从结果文件中读取线程数量和运行时间
threadCounts = []
runtime = []

with open("results.txt", "r") as file:
    lines = file.readlines()
    for i in range(0, len(lines), 4):
        threadCountLine = lines[i].rstrip().split(": ")
        runtimeLine = lines[i+2].rstrip().split(": ")

        threadCounts.append(int(threadCountLine[1]))
        runtime.append(int(runtimeLine[1].split()[0]))

plt.plot(threadCounts, runtime, marker='o', color='c', linestyle='-', linewidth=2)
plt.xlabel("Thread Count")
plt.ylabel("Runtime (microseconds)")
plt.title("Runtime vs Thread Count")

plt.savefig('results.jpg')
'''
在多线程计算中，线程数量的增加可以提高并行计算的效率，从而降低总体运行时间。然而，线程数量增加到一定程度后，额外增加的线程可能会产生一些负面影响，导致总体效率下降。

在开始阶段，增加线程数量会显著提高并行计算效率，因为任务可以更均匀地分配给多个线程并同时执行。这样可以充分利用多核处理器的优势，加快计算的速度，从而减少总体运行时间。

然而，当线程数量已经足够大，再进一步增加线程可能会带来一些负面影响。这是因为线程的创建、销毁以及线程间的调度都会引入一定的开销。过多的线程会导致线程切换增多，从而消耗了较多的CPU资源和内存，同时还会增加锁竞争等并发控制的开销。这样反而会降低并行计算的效率，造成总体时间的增加。

因此，对于多线程计算来说，线程数量的增加对总体时间的降低的贡献是递减的，即初始阶段增加线程数量对总时间的降低贡献较大，但随着线程数量的继续增加，额外增加的线程对总时间的降低贡献逐渐减小，甚至可能成为负面影响。

要确定最佳线程数量，需要考虑计算任务的性质、计算资源、并发控制等方面的因素，并进行实际测试和性能分析。优化多线程计算时，需要平衡线程数量与并行计算效率之间的关系。
'''
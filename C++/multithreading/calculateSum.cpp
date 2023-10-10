#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <numeric>
#include <chrono>

// 计算函数，进行累加运算
int calculateSum(const std::vector<int>& data, int start, int end) {
    int sum = std::accumulate(data.begin() + start, data.begin() + end + 1, 0);
    return sum;
}

int main() {
    constexpr int dataSize = 1000000; // 数据集大小
    const int maxThreadCount = std::thread::hardware_concurrency(); // 获取当前机器支持的最大线程数

    std::vector<int> data(dataSize);
    std::iota(data.begin(), data.end(), 1); // 生成从1到dataSize的连续整数序列

    std::vector<int> threadCounts = {1, 2, 4, 8, 16, 32, 64}; // 不同的线程数量
    threadCounts.push_back(maxThreadCount); // 添加最大线程数

    std::ofstream outputFile("results.txt"); // 创建输出文件

    for (int threadCount : threadCounts) {
        std::vector<std::thread> threads(threadCount); // 存储线程对象的容器
        std::vector<int> partialSums(threadCount); // 存储每个线程部分总和的容器

        auto startTime = std::chrono::steady_clock::now();

        // 创建并发执行的线程
        for (int i = 0; i < threadCount; i++) {
            int start = i * (dataSize / threadCount);
            int end = (i == threadCount - 1) ? (dataSize - 1) : ((i + 1) * (dataSize / threadCount) - 1);

            threads[i] = std::thread([&data, &partialSums, start, end, i]() {
                partialSums[i] = calculateSum(data, start, end);
            });
        }

        // 等待所有线程执行完毕
        for (auto& thread : threads) {
            thread.join();
        }

        // 计算最终的总和
        int totalSum = std::accumulate(partialSums.begin(), partialSums.end(), 0);

        auto endTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

        // 将结果写入文件
        outputFile << "Thread Count: " << threadCount << std::endl;
        outputFile << "Total Sum: " << totalSum << std::endl;
        outputFile << "Time taken: " << elapsedTime << " microseconds" << std::endl;
        outputFile << std::endl;
    }

    outputFile.close(); // 关闭文件

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

// 卷积层
class ConvolutionLayer {
private:
    int numFilters;
    int filterSize;
    std::vector<std::vector<std::vector<double>>> filters;

public:
    ConvolutionLayer(int numFilters, int filterSize) : numFilters(numFilters), filterSize(filterSize) {
        // 初始化卷积核
        filters.resize(numFilters, std::vector<std::vector<double>>(filterSize, std::vector<double>(filterSize)));
        // 随机初始化卷积核的值
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(-1.0, 1.0);
        for (int f = 0; f < numFilters; f++) {
            for (int i = 0; i < filterSize; i++) {
                for (int j = 0; j < filterSize; j++) {
                    filters[f][i][j] = dis(gen);
                }
            }
        }
    }

    std::vector<std::vector<double>> forward(std::vector<std::vector<double>> input) {
        int inputSize = input.size();
        int outputSize = inputSize - filterSize + 1;
        std::vector<std::vector<double>> output(outputSize, std::vector<double>(outputSize));

        for (int f = 0; f < numFilters; f++) {
            for (int i = 0; i < outputSize; i++) {
                for (int j = 0; j < outputSize; j++) {
                    for (int m = 0; m < filterSize; m++) {
                        for (int n = 0; n < filterSize; n++) {
                            output[i][j] += input[i + m][j + n] * filters[f][m][n];
                        }
                    }
                    output[i][j] = std::max(0.0, output[i][j]);  // 使用ReLU激活函数
                }
            }
        }

        return output;
    }
};

// 池化层
class PoolingLayer {
private:
    int poolSize;

public:
    PoolingLayer(int poolSize) : poolSize(poolSize) {}

    std::vector<std::vector<double>> forward(std::vector<std::vector<double>> input) {
        int inputSize = input.size();
        int outputSize = inputSize / poolSize;
        std::vector<std::vector<double>> output(outputSize, std::vector<double>(outputSize));

        for (int i = 0; i < outputSize; i++) {
            for (int j = 0; j < outputSize; j++) {
                double maxVal = input[i * poolSize][j * poolSize];
                for (int m = 0; m < poolSize; m++) {
                    for (int n = 0; n < poolSize; n++) {
                        maxVal = std::max(maxVal, input[i * poolSize + m][j * poolSize + n]);
                    }
                }
                output[i][j] = maxVal;
            }
        }

        return output;
    }
};

// 全连接层
class FullyConnectedLayer {
private:
    int inputSize;
    int outputSize;
    std::vector<std::vector<double>> weights;

public:
    FullyConnectedLayer(int inputSize, int outputSize) : inputSize(inputSize), outputSize(outputSize) {
        // 初始化权重
        weights.resize(outputSize, std::vector<double>(inputSize));
        // 随机初始化权重的值
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(-1.0, 1.0);
        for (int i = 0; i < outputSize; i++) {
            for (int j = 0; j < inputSize; j++) {
                weights[i][j] = dis(gen);
            }
        }
    }

    std::vector<double> forward(std::vector<double> input) {
        std::vector<double> output(outputSize);

        for (int i = 0; i < outputSize; i++) {
            for (int j = 0; j < inputSize; j++) {
                output[i] += input[j] * weights[i][j];
            }
            output[i] = std::max(0.0, output[i]);  // 使用ReLU激活函数
        }

        return output;
    }
};

int main() {
    // 创建一个简单的CNN模型
    int numFilters = 1;  // 一个卷积核
    int filterSize = 3;
    ConvolutionLayer convLayer(numFilters, filterSize);
    PoolingLayer poolLayer(2);
    FullyConnectedLayer fcLayer(4, 2);

    // 输入数据
    std::vector<std::vector<double>> input = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    // 前向传播
    std::vector<std::vector<double>> convOutput = convLayer.forward(input);
    std::vector<std::vector<double>> poolOutput = poolLayer.forward(convOutput);
    std::vector<double> flattenedOutput;
    for (const auto& row : poolOutput) {
        flattenedOutput.insert(flattenedOutput.end(), row.begin(), row.end());
    }
    std::vector<double> fcOutput = fcLayer.forward(flattenedOutput);

    // 输出结果
    std::cout << "Convolution Output:" << std::endl;
    for (const auto& row : convOutput) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Pooling Output:" << std::endl;
    for (const auto& row : poolOutput) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Flattened Output:" << std::endl;
    for (const auto& val : flattenedOutput) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "Fully Connected Output:" << std::endl;
    for (const auto& val : fcOutput) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
Convolution Output:
10.634 11.5414 12.4487 
15.1709 16.0782 16.9856 
19.7078 20.6151 21.5225 
Pooling Output:
16.0782 
Flattened Output:
16.0782 
Fully Connected Output:
13.5263 7.04696 
*/
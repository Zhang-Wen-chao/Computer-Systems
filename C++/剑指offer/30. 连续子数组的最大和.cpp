#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 函数声明
int FindGreatestSumOfSubArray(vector<int> array);

int main() {
    vector<int> array = {1, -2, 3, 10, -4, 7, 2, -5};
    int maxSum = FindGreatestSumOfSubArray(array);
    cout << "The greatest sum of subarrays is: " << maxSum << endl;
    return 0;
}

// 函数定义
int FindGreatestSumOfSubArray(vector<int> array) {
    if (array.empty()) return 0;

    int maxSum = array[0]; // 初始化为数组的第一个元素
    int currentSum = array[0]; // 当前子数组的和

    for (size_t i = 1; i < array.size(); ++i) {
        // 如果currentSum小于0，则从当前元素开始计算新的子数组的和
        currentSum = (currentSum < 0) ? array[i] : currentSum + array[i];
        // 更新最大和
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

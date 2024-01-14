#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

// 函数声明
vector<int> GetLeastNumbers_Solution(vector<int> input, int k);

int main() {
    vector<int> input = {4, 5, 1, 6, 2, 7, 3, 8};
    int k = 4;
    vector<int> result = GetLeastNumbers_Solution(input, k);

    // 输出最小的k个数
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// 函数定义
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (input.size() < k || k <= 0) {
        return vector<int>();
    }

    // 使用最大堆来维护最小的k个数
    priority_queue<int, vector<int>, less<int>> maxHeap;
    for (int num : input) {
        if (maxHeap.size() < k) {
            maxHeap.push(num);
        } else if (num < maxHeap.top()) {
            maxHeap.pop();
            maxHeap.push(num);
        }
    }

    vector<int> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top());
        maxHeap.pop();
    }

    return result;
}

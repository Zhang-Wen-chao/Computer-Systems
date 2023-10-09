#include <iostream>
#include <vector>
#include <algorithm>

// 获取数组中最大的元素
int getMax(const std::vector<int>& arr) {
    int max_element = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }
    return max_element;
}

// 对数组按照指定位数进行计数排序
void countSort(std::vector<int>& arr, int exp) {
    std::vector<int> output(arr.size());
    std::vector<int> count(10, 0);

    for (int i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp) % 10]++; // 统计当前位上元素的频次
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1]; // 计算累加频次
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; // 根据当前位上元素的值和频次，确定元素在输出数组中的位置
        count[(arr[i] / exp) % 10]--; // 更新频次
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i]; // 将输出数组复制回原数组
    }
}

// 基数排序主函数
void radixSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    int max_element = getMax(arr); // 获取数组中最大的元素

    // 根据每个位数进行计数排序
    for (int exp = 1; max_element / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

int main() {
    std::vector<int> arr = {329, 457, 657, 839, 436, 720, 355};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    radixSort(arr);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
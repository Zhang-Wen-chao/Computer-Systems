#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    int max_element = *std::max_element(arr.begin(), arr.end());
    int min_element = *std::min_element(arr.begin(), arr.end());

    int range = max_element - min_element + 1;
    std::vector<int> count(range, 0); // 创建计数数组

    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - min_element]++; // 统计元素出现的次数
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = i + min_element; // 按顺序重构排序数组
        }
    }
}

int main() {
    std::vector<int> arr = {4, 2, 5, 3, 1, 5, 2, 7, 3, 4, 5};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    countingSort(arr);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
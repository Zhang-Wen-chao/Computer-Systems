#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(std::vector<int>& arr, int num_buckets) {
    if (arr.empty() || num_buckets <= 0) {
        return;
    }

    int min_element = *std::min_element(arr.begin(), arr.end());
    int max_element = *std::max_element(arr.begin(), arr.end());

    int range = max_element - min_element + 1;
    std::vector<std::vector<int>> buckets(num_buckets); // 创建桶

    // 将元素分配到桶中
    for (int i = 0; i < arr.size(); i++) {
        int index = (arr[i] - min_element) * num_buckets / range;
        buckets[index].push_back(arr[i]);
    }

    // 对每个桶中的元素进行排序
    for (int i = 0; i < num_buckets; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }
    
    // 按照桶的顺序输出有序序列
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    std::vector<int> arr = {29, 25, 13, 49, 59, 33, 45, 65, 67, 37};
    int n = arr.size();
    int num_buckets = 5;

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    bucketSort(arr, num_buckets);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
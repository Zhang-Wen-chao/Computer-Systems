/*
stl中的堆排序
void heapSort(std::vector<int>& arr) {
    std::make_heap(arr.begin(), arr.end());  // 创建最大堆

    std::sort_heap(arr.begin(), arr.end());  // 从最大堆中排序元素
}
*/

#include <iostream>
#include <vector>
#include <algorithm>

//调整堆
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; //初始化根节点
    int left = 2 * i + 1; //左子节点
    int right = 2 * i + 2; //右子节点

    //左子节点比根节点大，则交换位置
    if (left < n && arr[left] > arr[largest])
        largest = left;

    //右子节点比根节点大，则交换位置
    if (right < n && arr[right] > arr[largest])
        largest = right;

    //如果根节点不是最大的，则继续调整
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        //递归调整子树
        heapify(arr, n, largest);
    }
}

//堆排序
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    //建立最大堆（从最后一个非叶子节点开始）
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    //一个一个从堆顶取出元素，并调整堆
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]); //将当前最大元素移到末尾
        heapify(arr, i, 0); //调整剩下的元素，生成最大堆
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    heapSort(arr);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
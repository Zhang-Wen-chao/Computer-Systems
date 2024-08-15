#include <iostream>
#include <random>
using namespace std;

// 交换元素
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 分区函数，返回基准元素的索引
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // 选择最后一个元素作为基准
    int i = low;  // 将 i 初始化为 low

    for (int j = low; j <= high - 1; j++) {
        // 如果当前元素小于或等于基准
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;  // 移动较小元素的边界
        }
    }
    swap(&arr[i], &arr[high]);
    return i;  // 返回基准元素的索引
}

// 快速排序函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 找到分区点
        int pi = partition(arr, low, high);
        // 递归地对左右子数组进行排序
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    random_device rd;  // 随机设备
    mt19937 gen(rd());  // 以随机设备为种子初始化随机数生成器
    uniform_int_distribution<> lengthDist(10, 50);  // 生成 10 到 50 之间的随机数组长度

    int arraySize = lengthDist(gen);  // 随机生成数组长度
    int arr[arraySize];

    uniform_int_distribution<> elementDist(1, 100);  // 生成 1 到 100 之间的随机整数
    for (int i = 0; i < arraySize; i++) {
        arr[i] = elementDist(gen);  // 使用随机数生成器填充数组
    }

    cout << "排序前的数组：\n";
    printArray(arr, arraySize);

    quickSort(arr, 0, arraySize - 1);

    cout << "排序后的数组：\n";
    printArray(arr, arraySize);

    return 0;
}
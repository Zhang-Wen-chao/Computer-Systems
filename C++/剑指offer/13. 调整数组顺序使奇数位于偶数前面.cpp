#include <iostream>
#include <vector>
#include <algorithm> // For std::swap function

void reOrderArray(std::vector<int> &array) {
    if (array.empty()) return;

    int start = 0;
    int end = array.size() - 1;
    while (start < end) {
        // Move start forward if it's pointing to an odd number
        while (start < end && (array[start] & 0x1) != 0)
            start++;
        // Move end backward if it's pointing to an even number
        while (start < end && (array[end] & 0x1) == 0)
            end--;
        if (start < end) {
            std::swap(array[start], array[end]);
        }
    }
}

int main() {
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Original array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    reOrderArray(array);

    std::cout << "Reordered array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

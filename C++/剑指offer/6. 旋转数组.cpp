#include <iostream>
#include <vector>
#include <exception>

int minInOrder(const std::vector<int>& numbers, int index1, int index2) {
    int result = numbers[index1];
    for (int i = index1 + 1; i <= index2; ++i) {
        if (result > numbers[i]) {
            result = numbers[i];
        }
    }
    return result;
}

int min(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Should not be an empty array.");
    }

    int index1 = 0;
    int index2 = numbers.size() - 1;
    int indexMid = index1; // Initialize indexMid with index1 for the case where the array is not rotated at all

    while (numbers[index1] >= numbers[index2]) {
        // When index1 and index2 are adjacent, index2 is the minimum
        if (index2 - index1 == 1) {
            indexMid = index2;
            break;
        }

        indexMid = (index1 + index2) / 2;

        // If the numbers at index1, index2 and indexMid are equal, we have to do a sequential search
        if (numbers[index1] == numbers[indexMid] && numbers[index2] == numbers[indexMid]) {
            return minInOrder(numbers, index1, index2);
        }

        // Narrow the search range
        if (numbers[indexMid] >= numbers[index1]) {
            index1 = indexMid;
        } else if (numbers[indexMid] <= numbers[index2]) {
            index2 = indexMid;
        }
    }

    return numbers[indexMid];
}

int main() {
    std::vector<int> numbers = {3, 4, 5, 1, 2};
    
    try {
        int minNumber = min(numbers);
        std::cout << "The minimum number in the rotated array is: " << minNumber << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}

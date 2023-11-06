#include <iostream>
#include <vector>

bool find_target(const std::vector<std::vector<int>>& array, int target) {
    if (array.empty() || array[0].empty()) {
        return false;
    }
    
    int rows = array.size();
    int cols = array[0].size();
    int row = 0;
    int col = cols - 1;
    
    while (row < rows && col >= 0) {
        if (array[row][col] == target) {
            return true;
        } else if (array[row][col] > target) {
            --col;
        } else {
            ++row;
        }
    }
    
    return false;
}

int main() {
    std::vector<std::vector<int>> array = {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}
    };
    
    int target = 7;
    if (find_target(array, target)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
    
    target = 3;
    if (find_target(array, target)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
    
    return 0;
}

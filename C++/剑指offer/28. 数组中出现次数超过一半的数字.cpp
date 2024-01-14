#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// 函数声明
int MoreThanHalfNum(vector<int>& numbers);

int main() {
    vector<int> numbers = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    try {
        int result = MoreThanHalfNum(numbers);
        cout << "The number that appears more than half: " << result << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}

// 函数定义
int MoreThanHalfNum(vector<int>& numbers) {
    int count = 0;
    int candidate;

    // Boyer-Moore Majority Vote Algorithm
    for (int num : numbers) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    // Verify the candidate
    count = 0;
    for (int num : numbers) {
        if (num == candidate) count++;
    }

    if (count > numbers.size() / 2) {
        return candidate;
    } else {
        throw invalid_argument("No number appears more than half in the array.");
    }
}

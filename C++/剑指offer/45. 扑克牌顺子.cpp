#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        if (numbers.empty()) return false;

        // Sort the numbers
        sort(numbers.begin(), numbers.end());

        int numberOfZeros = 0;
        int numberOfGaps = 0;

        // Count the number of zeros
        for (int i = 0; i < numbers.size() && numbers[i] == 0; ++i) {
            ++numberOfZeros;
        }

        // Count the gaps
        int small = numberOfZeros;
        int big = small + 1;
        while (big < numbers.size()) {
            // Two numbers are the same, not a continuous sequence
            if (numbers[small] == numbers[big]) return false;

            numberOfGaps += numbers[big] - numbers[small] - 1;
            small = big;
            ++big;
        }

        return numberOfGaps <= numberOfZeros;
    }
};

int main() {
    Solution solution;
    vector<int> numbers = {1, 3, 2, 5, 4}; // Example input
    bool result = solution.IsContinuous(numbers);
    if (result) {
        cout << "The numbers form a continuous sequence." << endl;
    } else {
        cout << "The numbers do not form a continuous sequence." << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to find the first duplicate number in the array
int findDuplicate(const vector<int>& nums) {
    unordered_set<int> seen;

    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return num; // Found the duplicate
        }
        seen.insert(num);
    }

    return -1; // No duplicate found
}

int main() {
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3}; // Example array

    int duplicate = findDuplicate(nums);

    if (duplicate != -1) {
        cout << "The first duplicate number is: " << duplicate << endl;
    } else {
        cout << "No duplicates found." << endl;
    }

    return 0;
}

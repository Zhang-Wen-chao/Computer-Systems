#include <iostream>
#include <vector>
#include <algorithm> // std::sort

using namespace std;

class Solution {
public:
    bool FindNumbersWithSum(const vector<int> &array, int sum, int &num1, int &num2) {
        bool found = false;
        int left = 0;
        int right = array.size() - 1;
        
        while (left < right) {
            int currentSum = array[left] + array[right];
            
            if (currentSum == sum) {
                num1 = array[left];
                num2 = array[right];
                found = true;
                break;
            } else if (currentSum < sum) {
                ++left;
            } else {
                --right;
            }
        }
        
        return found;
    }
};

int main() {
    Solution solution;
    vector<int> data = {1, 2, 4, 7, 11, 15};
    int sum = 15;
    int num1, num2;
    
    if (solution.FindNumbersWithSum(data, sum, num1, num2)) {
        cout << "The two numbers with sum " << sum << " are " << num1 << " and " << num2 << "." << endl;
    } else {
        cout << "No two numbers with sum " << sum << " found in the array." << endl;
    }
    
    return 0;
}

// 202. Happy Number
// https://leetcode.com/problems/happy-number/

#include <iostream>

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = getSquareSum(slow);
            fast = getSquareSum(getSquareSum(fast));
        } while (slow != fast);
        
        return slow == 1;
    }
    
    int getSquareSum(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    std::cout << sol.isHappy(19) << std::endl;
    
    return 0;
}

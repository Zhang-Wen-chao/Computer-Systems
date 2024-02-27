#include <iostream>

using namespace std;

class Solution {
public:
    static int Sum_Solution(int n) {
        sum = 0; // Reset sum for each call
        Add(n);
        return sum;
    }

private:
    static int sum; // Static member to keep the running total

    static void Add(int n) {
        sum += n;
        // The condition to stop the recursion is implemented by the function itself
        // When n is 0, no more additions are made
        if (n > 0) {
            Add(n - 1);
        }
    }
};

int Solution::sum = 0; // Initialize the static member

int main() {
    int result = Solution::Sum_Solution(10); // Calculate 1+2+3+...+10
    cout << "The sum is: " << result << endl;
    return 0;
}

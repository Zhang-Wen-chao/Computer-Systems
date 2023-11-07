#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if (n < 1 || m < 1) return -1; // Invalid input

        int last = 0;
        for (int i = 2; i <= n; i++) {
            last = (last + m) % i;
        }

        return last;
    }
};

int main() {
    Solution solution;
    int n = 5; // Total number of children
    int m = 3; // The m-th child will be eliminated
    int lastRemaining = solution.LastRemaining_Solution(n, m);
    cout << "The last remaining child is at position: " << lastRemaining << endl;
    return 0;
}

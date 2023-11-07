#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        return helper(threshold, rows, cols, 0, 0, visited);
    }

private:
    int helper(int threshold, int rows, int cols, int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j] || !isValid(threshold, i, j)) {
            return 0;
        }
        visited[i][j] = true;
        return 1 + helper(threshold, rows, cols, i + 1, j, visited)
                 + helper(threshold, rows, cols, i - 1, j, visited)
                 + helper(threshold, rows, cols, i, j + 1, visited)
                 + helper(threshold, rows, cols, i, j - 1, visited);
    }

    bool isValid(int threshold, int i, int j) {
        int sum = 0;
        while (i) {
            sum += i % 10;
            i /= 10;
        }
        while (j) {
            sum += j % 10;
            j /= 10;
        }
        return sum <= threshold;
    }
};

int main() {
    Solution solution;
    int threshold = 5;
    int rows = 10;
    int cols = 10;
    int count = solution.movingCount(threshold, rows, cols);
    cout << "The robot can reach " << count << " cells." << endl;
    return 0;
}

// 77. Combinations
// https://leetcode.com/problems/combinations/

#include <vector>
#include "../printUtils.hpp"

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> curr;
        backtrack(result, curr, n, k, 1);
        return result;
    }

private:
    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& curr, int n, int k, int start) {
        if (curr.size() == k) {
            result.push_back(curr);
            return;
        }
        
        // Pruning condition: i <= n - (k - curr.size()) + 1
        for (int i = start; i <= n - (k - curr.size()) + 1; i++) {
            curr.push_back(i);
            backtrack(result, curr, n, k, i + 1);
            curr.pop_back();
        }
    }
};

int main() {
    printSet(Solution().combine(4, 2));

    return 0;
}

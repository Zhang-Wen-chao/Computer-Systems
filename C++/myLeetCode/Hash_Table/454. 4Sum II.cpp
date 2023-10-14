// 454. 4Sum II
// https://leetcode.com/problems/4sum-ii/
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int fourSumCount(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D) {
        std::unordered_map<int, int> AB_sum;
        for (int a : A) {
            for (int b : B) {
                AB_sum[a + b]++;
            }
        }

        int count = 0;
        for (int c : C) {
            for (int d : D) {
                if (AB_sum.find(-c - d) != AB_sum.end()) {
                    count += AB_sum[-c - d];
                }
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    std::vector<int> A = {1, 2};
    std::vector<int> B = {-2, -1};
    std::vector<int> C = {-1, 2};
    std::vector<int> D = {0, 2};
    std::cout << s.fourSumCount(A, B, C, D) << std::endl;
    return 0;
}
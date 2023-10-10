// 454. 4Sum II
// https://leetcode.com/problems/4sum-ii/
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int fourSumCount(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D) {
        std::unordered_map<int, int> sumCount;
        int count = 0;

        // 计算 A 和 B 数组中元素的所有可能和的出现次数
        for (int a : A) {
            for (int b : B) {
                sumCount[a + b]++;
            }
        }

        // 查找 C 和 D 数组中元素的和在 sumCount 中的相反数出现的次数
        for (int c : C) {
            for (int d : D) {
                count += sumCount[-(c + d)];
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
// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// clang++ 17.\ Letter\ Combinations\ of\ a\ Phone\ Number.cpp -std=c++17

#include <string>
#include "../printUtils.hpp"

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> ans; // 存储最终结果
        if (digits.empty()) return ans; // 如果输入为空，直接返回空结果
        std::string path; // 存储当前路径
        std::vector<std::string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // 存储数字对应的字母
        backtrack(digits, 0, dict, ans, path); // 从第0位数字开始搜索
        return ans;
    }

private:
    void backtrack(std::string& digits, int index, std::vector<std::string>& dict, std::vector<std::string>& ans, std::string& path) {
        if (index == digits.size()) { // 如果已经遍历完所有数字，说明找到一个组合
            ans.push_back(path); // 加入到结果中
            return;
        }
        std::string letters = dict[digits[index] - '2']; // 获取当前数字对应的字母
        for (char c : letters) { // 遍历每个字母
            path.push_back(c); // 将当前字母加入到路径中
            backtrack(digits, index + 1, dict, ans, path); // 递归搜索下一位数字
            path.pop_back(); // 回溯，将当前字母从路径中移除
        }
    }
};

int main() {
    printArray(Solution().letterCombinations("23"));
    
    return 0;
}

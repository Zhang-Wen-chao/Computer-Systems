// 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/

#include <string>
#include "../printUtils.hpp"

class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> ans; // 存储最终结果
        std::vector<std::string> path; // 存储当前路径
        backtrack(s, 0, ans, path); // 从第0个字符开始搜索
        return ans;
    }

private:
    void backtrack(std::string& s, int start, std::vector<std::vector<std::string>>& ans, std::vector<std::string>& path) {
        if (start == s.size()) { // 如果已经遍历完所有字符，说明找到一个分割方案
            ans.push_back(path); // 加入到结果中
            return;
        }
        for (int i = start; i < s.size(); i++) { // 遍历每个可能的分割点
            std::string sub = s.substr(start, i - start + 1); // 获取当前子串
            if (isPalindrome(sub)) { // 如果当前子串是回文串，才继续搜索
                path.push_back(sub); // 将当前子串加入到路径中
                backtrack(s, i + 1, ans, path); // 递归搜索下一段子串
                path.pop_back(); // 回溯，将当前子串从路径中移除
            }
        }
    }

    bool isPalindrome(std::string& s) { // 判断一个字符串是否是回文串
        int left = 0; // 左指针
        int right = s.size() - 1; // 右指针
        while (left < right) { // 当左右指针相遇时，结束循环
            if (s[left] != s[right]) return false; // 如果左右指针指向的字符不相等，说明不是回文串，返回false
            left++; // 左指针右移一位
            right--; // 右指针左移一位
        }
        return true; // 如果循环结束，说明是回文串，返回true
    }
};

int main() {
    printSet(Solution().partition("aab"));

    printSet(Solution().partition("a"));

    return 0;
}

// 93. Restore IP Addresses
// https://leetcode.com/problems/restore-ip-addresses/

#include <string>
#include "../printUtils.hpp"

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> ans; // 存储最终结果
        std::string path; // 存储当前路径
        backtrack(s, 0, 0, ans, path); // 从第0个字符和第0段开始搜索
        return ans;
    }

private:
    void backtrack(std::string& s, int start, int segment, std::vector<std::string>& ans, std::string& path) {
        if (start == s.size() && segment == 4) { // 如果已经遍历完所有字符且分成了4段，说明找到一个合法的IP地址
            ans.push_back(path.substr(0, path.size() - 1)); // 加入到结果中，注意去掉最后一个点
            return;
        }
        if (start == s.size() || segment == 4) return; // 如果已经遍历完所有字符或者已经分成了4段，但是另一个条件不满足，说明不是合法的IP地址，直接返回
        for (int i = start; i < s.size(); i++) { // 遍历每个可能的分割点
            std::string sub = s.substr(start, i - start + 1); // 获取当前子串
            if (isValid(sub)) { // 如果当前子串是合法的IP段，才继续搜索
                path += sub + "."; // 将当前子串加入到路径中，并加上一个点
                backtrack(s, i + 1, segment + 1, ans, path); // 递归搜索下一段子串
                path.erase(path.size() - sub.size() - 1); // 回溯，将当前子串和点从路径中移除
            }
        }
    }

    bool isValid(std::string& s) { // 判断一个字符串是否是合法的IP段
        if (s.empty() || s.size() > 3) return false; // 如果字符串为空或者长度大于3，说明不合法，返回false
        if (s[0] == '0' && s.size() > 1) return false; // 如果字符串以0开头且长度大于1，说明不合法，返回false
        int num = std::stoi(s); // 将字符串转换为整数
        if (num < 0 || num > 255) return false; // 如果整数小于0或者大于255，说明不合法，返回false
        return true; // 如果以上条件都不满足，说明合法，返回true
    }
};

int main() {
    printSet(Solution().restoreIpAddresses("25525511135"));

    printSet(Solution().restoreIpAddresses("0000"));

    printSet(Solution().restoreIpAddresses("1111"));

    return 0;
}

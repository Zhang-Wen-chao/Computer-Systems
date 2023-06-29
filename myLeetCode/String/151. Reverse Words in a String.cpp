// 151. Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::string reverseWords(std::string str) {
    std::istringstream iss(str);
    std::vector<std::string> words;
    
    // 将字符串按照空格分割为单词
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    
    std::reverse(words.begin(), words.end());
    
    // 将单词拼接为反转后的字符串
    std::string result;
    for (const std::string& w : words) {
        result += w + " ";
    }
    
    // 去除末尾的空格并返回结果
    if (!result.empty()) {
        result.pop_back();
    }
    
    return result;
}

int main() {
    std::string str = "the sky is blue";
    
    std::string result = reverseWords(str);
    
    std::cout << result << std::endl;
    
    return 0;
}

// 28. Find the Index of the First Occurrence in a String
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <iostream>

int firstOccurrence(std::string haystack, std::string needle) {
    return haystack.find(needle);
}

int main() {
    std::string haystack = "hello world";
    std::string needle = "world";
    // std::string needle = "qq";
    
    int result = firstOccurrence(haystack, needle);
    
    std::cout << "Index of first occurrence: " << result << std::endl;
    
    return 0;
}

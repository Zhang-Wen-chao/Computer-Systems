// 763. Partition Labels
// https://leetcode.com/problems/partition-labels/

#include <iostream>
#include <vector>
#include <unordered_map>
#include "../printUtils.hpp"

std::vector<int> partitionLabels(std::string s) {
    std::unordered_map<char, int> lastOccurrence;
    int n = s.length();

    // 记录每个字符最后出现的位置
    for (int i = 0; i < n; i++) {
        lastOccurrence[s[i]] = i;
    }

    std::vector<int> partitions;
    int start = 0;
    int end = 0;

    // 根据每个字符最后出现的位置进行分割
    for (int i = 0; i < n; i++) {
        end = std::max(end, lastOccurrence[s[i]]);
        if (i == end) {
            partitions.push_back(end - start + 1);
            start = end + 1;
        }
    }

    return partitions;
}

int main() {
    std::string input = "ababcbacadefegdehijhklij";
    std::cout << "Partition Labels: ";
    printSet(partitionLabels(input));
    std::cout << std::endl;

    std::string input2 = "eccbbbbdec";
    std::cout << "Partition Labels: ";
    printSet(partitionLabels(input2));
    std::cout << std::endl;

    return 0;
}

// 501. Find Mode in Binary Search Tree
// https://leetcode.com/problems/find-mode-in-binary-search-tree/
// clang++ 501.\ Find\ Mode\ in\ Binary\ Search\ Tree.cpp -std=c++17
#include <unordered_map>
#include "../../printUtils.hpp"

template<typename T>
class Solution {
public:
    std::vector<T> findMode(TreeNode<T>* root) {
        std::vector<T> modes;
        std::unordered_map<T, int> frequencyMap;

        traverse(root, frequencyMap);
        int maxFrequency = 0;
        for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
            maxFrequency = std::max(maxFrequency, it->second);
        }
        // 将所有频率等于最大频率的节点值添加到结果向量中
        for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
            if (it->second == maxFrequency) {
                modes.push_back(it->first);
            }
        }

        return modes;
    }

    void traverse(TreeNode<T>* node, std::unordered_map<T, int>& frequencyMap) {
        if (node == nullptr) {
            return;
        }

        frequencyMap[node->val]++;

        traverse(node->left, frequencyMap);
        traverse(node->right, frequencyMap);
    }
};

int main() {
    TreeNode<int>* root = buildTree({1, -1, 2, 2}, -1);
    std::cout << "Modes: " << std::endl;
    printArray(Solution<int>().findMode(root));

    return 0;
}
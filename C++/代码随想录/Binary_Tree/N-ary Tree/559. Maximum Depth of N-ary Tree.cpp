// 559. Maximum Depth of N-ary Tree
// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// clang++ 559.\ Maximum\ Depth\ of\ N-ary\ Tree.cpp -std=c++17
#include "../../printUtils.hpp"

template<typename T>
int maxDepth(NTreeNode<T>* root) {
    if (root == nullptr) return 0;

    int depth = 0;
    for (NTreeNode<T>* child : root->children) {
        depth = std::max(depth, maxDepth(child));
    }

    return depth + 1;
}

int main() {
    // NTreeNode<int>* root = buildNTree<int>({1, -1, 3, 2, 4, -1, 5, 6}, -1);
    NTreeNode<int>* root = buildNTree<int>({1,-1,2,3,4,5,-1,-1,6,7,-1,8,-1,9,10,-1,-1,11,-1,12,-1,13,-1,-1,14}, -1);
    std::cout << "Maximum depth of the N-ary tree: " << maxDepth(root) << std::endl;
    deleteNTree(root);
    
    return 0;
}

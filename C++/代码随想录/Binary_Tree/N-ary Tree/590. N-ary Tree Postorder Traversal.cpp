// 590. N-ary Tree Postorder Traversal
// https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// clang++ 590.\ N-ary\ Tree\ Postorder\ Traversal.cpp -std=c++17

#include "../../printUtils.hpp"
#include <stack>
#include <algorithm>

template<typename T>
std::vector<T> postorder(NTreeNode<T>* root) {
    std::vector<T> result;
    if (root == nullptr) {
        return result;
    }

    std::stack<NTreeNode<T>*> stk;
    stk.push(root);

    while (!stk.empty()) {
        NTreeNode<T>* curr = stk.top();
        stk.pop();

        result.push_back(curr->val);

        for (NTreeNode<T>* child : curr->children) {
            stk.push(child);
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    NTreeNode<int>* root = buildNTree<int>({1, -1, 3, 2, 4, -1, 5, 6}, -1);
    // NTreeNode<int>* root = buildNTree<int>({1,-1,2,3,4,5,-1,-1,6,7,-1,8,-1,9,10,-1,-1,11,-1,12,-1,13,-1,-1,14}, -1);
    printArray(postorder(root));
    deleteNTree(root);
    
    return 0;
}
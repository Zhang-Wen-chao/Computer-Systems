// 589. N-ary Tree Preorder Traversal
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// clang++ 589.\ N-ary\ Tree\ Preorder\ Traversal.cpp -std=c++17

#include "../../printUtils.hpp"
#include <stack>

template <typename T>
std::vector<T> preorder(NTreeNode<T>* root) {
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
        
        for (int i = curr->children.size() - 1; i >= 0; i--) {
            stk.push(curr->children[i]);
        }
    }
    
    return result;
}

int main() {
    // NTreeNode<int>* root = buildNTree<int>({1, -1, 3, 2, 4, -1, 5, 6}, -1);
    NTreeNode<int>* root = buildNTree<int>({1,-1,2,3,4,5,-1,-1,6,7,-1,8,-1,9,10,-1,-1,11,-1,12,-1,13,-1,-1,14}, -1);
    printArray(preorder(root));
    deleteNTree(root);
    
    return 0;
}

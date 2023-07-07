// 589. N-ary Tree Preorder Traversal
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

#include "../../BinaryTreeUtils.hpp"
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
    NTreeNode<int>* root = new NTreeNode<int>(1);
    NTreeNode<int>* child1 = new NTreeNode<int>(3);
    NTreeNode<int>* child2 = new NTreeNode<int>(2);
    NTreeNode<int>* child3 = new NTreeNode<int>(4);
    NTreeNode<int>* child4 = new NTreeNode<int>(5);
    NTreeNode<int>* child5 = new NTreeNode<int>(6);

    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);

    child1->children.push_back(child4);
    child1->children.push_back(child5);

    printArray(preorder(root));
    std::cout << std::endl;

    // Clean up the allocated memory
    // deleteTree(root);



    return 0;
}

#include <iostream>

using namespace std;

// Definition for binary tree with a parent pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *parent;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode == nullptr) return nullptr;

        // If there is a right subtree, then the next node is the leftmost node in the right subtree.
        if (pNode->right != nullptr) {
            TreeLinkNode* node = pNode->right;
            while (node->left != nullptr) node = node->left;
            return node;
        }

        // If there is no right subtree and pNode is the left child of its parent,
        // then the next node is its parent.
        while (pNode->parent != nullptr && pNode->parent->right == pNode) {
            pNode = pNode->parent;
        }
        return pNode->parent;
    }
};

int main() {
    // Construct a binary tree as an example
    TreeLinkNode a(1);
    TreeLinkNode b(2);
    TreeLinkNode c(3);
    TreeLinkNode d(4);
    TreeLinkNode e(5);
    TreeLinkNode f(6);
    TreeLinkNode g(7);

    a.left = &b; a.right = &c;
    b.parent = &a; c.parent = &a;

    b.left = &d; b.right = &e;
    d.parent = &b; e.parent = &b;

    c.left = &f; c.right = &g;
    f.parent = &c; g.parent = &c;

    // Assuming we want to find the next node of 'e'
    Solution solution;
    TreeLinkNode* nextNode = solution.GetNext(&e);

    if (nextNode) {
        cout << "The next node of node " << e.val << " is " << nextNode->val << "." << endl;
    } else {
        cout << "The next node of node " << e.val << " does not exist." << endl;
    }

    return 0;
}

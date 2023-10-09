// ''' 
// To implement conversion of Binary-Search-Tree (BST) to Doubly-Linked-List(DLList).
// The input parameter of the function is the root node of BST, and 
// the function returns the head node of DLList. 
// The order of the nodes on the forward list follows the in-order traversing of BST.
// For example, the DLList "4 <-> 6 <-> 8 <-> 10 <-> 11 <-> 12 <-> 16" is converted from the following complete BST:
//              10
//         6          12
//      4     8   11      16
// '''
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder (TreeNode* root, TreeNode*& prev, TreeNode*& head){
  if(!root) 
    return;

  inorder(root->left, prev, head);

  if(!prev) {
    head =root;
  } else {
    prev->right = root;
    root->left = prev;
  }
  prev = root;

  inorder(root->right, prev, head);
}

TreeNode* convertToLinkedList(TreeNode* root) {
  if (!root)
    return nullptr;

  TreeNode* prev = nullptr;
  TreeNode* head = nullptr;

  inorder(root, prev, head);

  return head;
}
int main() {
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(6);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(16);

    TreeNode* head = convertToLinkedList(root);

    while (head != NULL) {
        cout << head->val << " ";
        head = head->right;
    }
    
    return 0;
}
// 编译过程：g++ -o mayi mayi.cpp
// 运行过程：./mayi
// 输出结果：4 6 8 10 11 12 16
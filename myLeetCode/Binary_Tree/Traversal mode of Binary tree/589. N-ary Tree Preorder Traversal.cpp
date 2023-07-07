// 589. N-ary Tree Preorder Traversal
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

#include <iostream>
#include <vector>
#include <stack>

// N叉树节点定义
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}
    
    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// 前序遍历 N 叉树（迭代版本）
std::vector<int> preorder(Node* root) {
    std::vector<int> result;
    if (root == nullptr) {
        return result;
    }
    
    std::stack<Node*> stk;
    stk.push(root);
    
    while (!stk.empty()) {
        Node* curr = stk.top();
        stk.pop();
        
        result.push_back(curr->val);
        
        for (int i = curr->children.size() - 1; i >= 0; i--) {
            stk.push(curr->children[i]);
        }
    }
    
    return result;
}

int main() {
    // 构建测试 N 叉树
    Node* root = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    root->children.push_back(node3);
    root->children.push_back(node2);
    root->children.push_back(node4);
    node3->children.push_back(node5);
    node3->children.push_back(node6);

    // 前序遍历 N 叉树
    std::vector<int> result = preorder(root);

    // 打印遍历结果
    std::cout << "Preorder traversal: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

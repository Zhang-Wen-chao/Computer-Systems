// 429. N-ary Tree Level Order Traversal
// https://leetcode.com/problems/n-ary-tree-level-order-traversal/


#include <iostream>
#include <vector>
#include <queue>

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

// N叉树层序遍历函数
std::vector<std::vector<int>> levelOrder(Node* root) {
    std::vector<std::vector<int>> result;
    if (root == nullptr) {
        return result;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        std::vector<int> level;

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            level.push_back(curr->val);

            for (Node* child : curr->children) {
                q.push(child);
            }
        }

        result.push_back(level);
    }

    return result;
}

int main() {
    // 构建测试N叉树
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

    // 获取N叉树的层序遍历结果
    std::vector<std::vector<int>> result = levelOrder(root);

    // 打印遍历结果
    std::cout << "Level Order Traversal of N-ary Tree:" << std::endl;
    for (const auto& level : result) {
        for (int val : level) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

// 116. Populating Next Right Pointers in Each Node
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// 117. Populating Next Right Pointers in Each Node II
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

// 这两道题的代码完全一样。
#include <iostream>
#include <queue>

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x, Node* left, Node* right, Node* next)
        : val(x), left(left), right(right), next(next) {}
};

Node* connect(Node* root) {
    if (root == nullptr) return nullptr;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        Node* prev = nullptr;

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            if (prev) prev->next = curr;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);

            prev = curr;
        }
    }

    return root;
}

// Utility function to print the next pointers
void printNextPointers(Node* root) {
    Node* currLevel = root;

    while (currLevel != nullptr) {
        Node* curr = currLevel;

        while (curr != nullptr) {
            std::cout << curr->val << " -> ";
            curr = curr->next;
        }

        std::cout << "nullptr" << std::endl;
        currLevel = currLevel->left;
    }
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* connectedRoot = connect(root);
    std::cout << "Next pointers:" << std::endl;
    printNextPointers(connectedRoot);

    // Clean up
    delete root->right->right;
    // delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}

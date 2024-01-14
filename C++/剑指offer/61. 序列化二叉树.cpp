#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";
        string data;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                data += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                data += "null,";
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null") return nullptr;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (getline(s, str, ',')) {
                if (str != "null") {
                    node->left = new TreeNode(stoi(str));
                    q.push(node->left);
                }
                if (getline(s, str, ',')) {
                    if (str != "null") {
                        node->right = new TreeNode(stoi(str));
                        q.push(node->right);
                    }
                }
            }
        }
        return root;
    }
};

void printInOrder(TreeNode* root) {
    if (root) {
        printInOrder(root->left);
        cout << root->val << " ";
        printInOrder(root->right);
    }
}

int main() {
    // Your Codec object will be instantiated and called as such:
    Codec codec;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serialized = codec.serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    TreeNode* deserialized = codec.deserialize(serialized);
    cout << "Deserialized tree (in-order): ";
    printInOrder(deserialized);
    cout << endl;

    // Clean up memory if needed
    // ...

    return 0;
}

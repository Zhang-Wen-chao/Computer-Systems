#ifndef NARYTREEUTILS_HPP
#define NARYTREEUTILS_HPP

#include <vector>
#include <queue>

// Definition for a Node in an N-ary Tree
template<typename T>
struct NTreeNode {
    T val;
    std::vector<NTreeNode*> children;
    NTreeNode(T x) : val(x) {}
};

// Utility function to build an N-ary Tree from a vector
template<typename T>
NTreeNode<T>* buildNTree(const std::vector<T>& nodes, const T& nullValue) {
    if (nodes.empty() || nodes[1] != nullValue) {
        return nullptr;
    }

    NTreeNode<T>* root = new NTreeNode<T>(nodes[0]);
    std::queue<NTreeNode<T>*> nodeQueue;
    nodeQueue.push(root);

    int i = 2; // Start from index 2 to skip the root node and the -1 marking the end of its children

    while (!nodeQueue.empty() && i < nodes.size()) {
        int levelSize = nodeQueue.size();

        for (int j = 0; j < levelSize; j++) {
            NTreeNode<T>* currNode = nodeQueue.front();
            nodeQueue.pop();

            while (i < nodes.size() && nodes[i] != nullValue) {
                NTreeNode<T>* childNode = new NTreeNode<T>(nodes[i]);
                currNode->children.push_back(childNode);
                nodeQueue.push(childNode);
                i++;
            }

            i++; // Skip the null value marking the end of children for the current node
        }
    }

    return root;
}

// Utility function to delete an N-ary Tree
template <typename T>
void deleteNTree(NTreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }

    for (NTreeNode<T>* child : root->children) {
        deleteNTree(child);
    }

    delete root;
}

#endif // NARYTREEUTILS_HPP
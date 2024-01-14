#include <iostream>
#include <vector>

using namespace std;

bool verifySequenceOfBST(vector<int>& sequence, int start, int end) {
    if (start >= end) return true; // 当前序列为空或者只有一个节点

    int root = sequence[end]; // 后序遍历中最后一个数是根节点
    int i = start;
    // 在二叉搜索树中左子树节点小于根节点
    while (i < end && sequence[i] < root) i++;

    // 右子树中的节点都应该大于根节点
    for (int j = i; j < end; j++) {
        if (sequence[j] < root) return false;
    }

    // 递归检查左子树和右子树
    return verifySequenceOfBST(sequence, start, i - 1) &&
           verifySequenceOfBST(sequence, i, end - 1);
}

bool verifySequenceOfBST(vector<int>& sequence) {
    if (sequence.empty()) return false;
    return verifySequenceOfBST(sequence, 0, sequence.size() - 1);
}

int main() {
    vector<int> sequence = {5, 7, 6, 9, 11, 10, 8};
    if (verifySequenceOfBST(sequence)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

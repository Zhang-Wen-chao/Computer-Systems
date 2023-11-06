// 429. N-ary Tree Level Order Traversal
// https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// clang++ 429.\ N-ary\ Tree\ Level\ Order\ Traversal.cpp -std=c++17


//     NTreeNode<int>* root = buildNTree<int>({1,-1,2,3,4,5,-1,-1,6,7,-1,8,-1,9,10,-1,-1,11,-1,12,-1,13,-1,-1,14}, -1);
// 我们可以这么划分数组：
// 1,-1：代表了1是第一层的根节点
// 2,3,4,5,-1：代表了2,3,4,5是根节点的孩子
// -1：代表了第二层的第一个节点2，没有孩子节点。
// 6,7,-1：代表了第二层的第二个节点3，有两个孩子6和7
// 8,-1：代表了第二层的第三个节点4，有一个孩子8
// 9,10,-1：代表了第二层的第四个节点5，有两个孩子9和10
// -1：代表了第三层的第一个节点6，没有孩子节点。
// 11,-1：代表了第三层的第二个节点7，有一个孩子11
// 12,-1：代表了第三层的第三个节点8，有一个孩子12
// 13,-1：代表了第三层的第三个节点9，有一个孩子13
// -1：代表了第三层的第四个节点10，没有孩子节点。
// 14：代表了第四层的第1个节点11，有一个孩子14
// 除了数组前两个元素固定是：根节点和-1代表结束外。
// 往下的层，其实它没有层结束的概念，只有孩子结点结束的概念，层结束是依靠计算节点数量来判断的。
// 现在你应该很明白规则了，那你复述一遍，然后再重写一下buildNTree，我看你是否真正理解了。

#include "../../printUtils.hpp"

// Function to perform level order traversal of an N-ary Tree
template<typename T>
std::vector<std::vector<T>> levelOrderNTree(NTreeNode<T>* root) {
    if (!root) {
        return {};
    }

    std::vector<std::vector<T>> result;
    std::queue<NTreeNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        int cnt = q.size();
        std::vector<T> level;
        for (int i = 0; i < cnt; ++i) {
            NTreeNode<T>* cur = q.front();
            q.pop();
            level.push_back(cur->val);
            for (NTreeNode<T>* child: cur->children) {
                q.push(child);
            }
        }
        result.push_back(std::move(level));
    }

    return result;
}

int main() {
    NTreeNode<int>* root = buildNTree<int>({1,-1,2,3,4,5,-1,-1,6,7,-1,8,-1,9,10,-1,-1,11,-1,12,-1,13,-1,-1,14}, -1);
    // NTreeNode<int>* root = buildNTree<int>({1, -1, 3, 2, 4, -1, 5, 6}, -1);
    printArray(levelOrderNTree(root));
    deleteNTree(root);
    
    return 0;
}
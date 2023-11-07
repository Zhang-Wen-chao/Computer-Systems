#include <iostream>
#include <unordered_map>

using namespace std;

// 定义复杂链表的结构
class RandomListNode {
public:
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

// 函数声明
RandomListNode* copyRandomList(RandomListNode* head);

int main() {
    // 构建复杂链表
    RandomListNode* node1 = new RandomListNode(1);
    RandomListNode* node2 = new RandomListNode(2);
    RandomListNode* node3 = new RandomListNode(3);
    node1->next = node2;
    node2->next = node3;
    node1->random = node3;
    node2->random = node1;

    // 复制复杂链表
    RandomListNode* newHead = copyRandomList(node1);
    RandomListNode* curr = newHead;
    while (curr != nullptr) {
        cout << "Label: " << curr->label;
        if (curr->random != nullptr) {
            cout << ", Random: " << curr->random->label;
        }
        cout << endl;
        curr = curr->next;
    }

    // 清理内存，注意：这里没有删除原始链表和复制的链表中的所有节点，这只是为了示例。
    // 在实际应用中，你需要确保正确地删除所有节点以避免内存泄漏。
    delete node1;
    delete node2;
    delete node3;
    // 也需要删除复制的链表中的所有节点
    // ...

    return 0;
}

// 函数定义
RandomListNode* copyRandomList(RandomListNode* head) {
    if (!head) return nullptr;

    unordered_map<RandomListNode*, RandomListNode*> map;
    RandomListNode* newHead = new RandomListNode(head->label);
    RandomListNode* oldNode = head;
    RandomListNode* newNode = newHead;
    map[oldNode] = newNode;

    // 复制next指针和构建原节点到新节点的映射
    while (oldNode->next) {
        newNode->next = new RandomListNode(oldNode->next->label);
        oldNode = oldNode->next;
        newNode = newNode->next;
        map[oldNode] = newNode;
    }

    // 设置random指针
    oldNode = head;
    newNode = newHead;
    while (oldNode) {
        if (oldNode->random) {
            newNode->random = map[oldNode->random];
        }
        oldNode = oldNode->next;
        newNode = newNode->next;
    }

    return newHead;
}

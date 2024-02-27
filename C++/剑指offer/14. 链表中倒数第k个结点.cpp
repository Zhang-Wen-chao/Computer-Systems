#include <iostream>

// 定义链表结构
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 函数声明
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);

int main() {
    // 构建链表
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // 调用函数查找倒数第k个节点
    ListNode* result = FindKthToTail(head, 2);
    if (result != nullptr) {
        std::cout << "The value of the node is: " << result->val << std::endl;
    } else {
        std::cout << "The k is larger than the length of the list." << std::endl;
    }

    // 清理内存
    delete head;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}

// 函数定义
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if (pListHead == nullptr || k == 0) {
        return nullptr;
    }

    ListNode *pAhead = pListHead;
    ListNode *pBehind = nullptr;

    for (unsigned int i = 0; i < k - 1; ++i) {
        if (pAhead->next != nullptr) {
            pAhead = pAhead->next;
        } else {
            // 如果k大于链表长度，返回nullptr
            return nullptr;
        }
    }

    pBehind = pListHead;
    while (pAhead->next != nullptr) {
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }

    return pBehind;
}

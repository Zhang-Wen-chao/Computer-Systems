#include <iostream>

// 定义链表结构
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 函数声明
ListNode* ReverseList(ListNode* pHead);

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

    // 打印原始链表
    std::cout << "Original list: ";
    for (ListNode* node = head; node != nullptr; node = node->next) {
        std::cout << node->val << " ";
    }
    std::cout << std::endl;

    // 反转链表
    ListNode* reversedHead = ReverseList(head);

    // 打印反转后的链表
    std::cout << "Reversed list: ";
    for (ListNode* node = reversedHead; node != nullptr; node = node->next) {
        std::cout << node->val << " ";
    }
    std::cout << std::endl;

    // 清理内存
    while (reversedHead != nullptr) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}

// 函数定义
ListNode* ReverseList(ListNode* pHead) {
    ListNode *pReversedHead = nullptr;
    ListNode *pNode = pHead;
    ListNode *pPrev = nullptr;
    while (pNode != nullptr) {
        ListNode *pNext = pNode->next;
        if (pNext == nullptr) {
            pReversedHead = pNode;
        }
        pNode->next = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    return pReversedHead;
}

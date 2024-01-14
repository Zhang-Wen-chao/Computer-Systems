#include <iostream>

// 定义链表结构
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 函数声明
ListNode* Merge(ListNode* pHead1, ListNode* pHead2);

int main() {
    // 构建两个有序链表
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    // 合并两个链表
    ListNode* mergedList = Merge(list1, list2);

    // 打印合并后的链表
    std::cout << "Merged list: ";
    while (mergedList != nullptr) {
        std::cout << mergedList->val << " ";
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp; // 删除节点释放内存
    }
    std::cout << std::endl;

    return 0;
}

// 函数定义
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == nullptr) return pHead2;
    if (pHead2 == nullptr) return pHead1;

    ListNode* pMergedHead = nullptr;

    if (pHead1->val < pHead2->val) {
        pMergedHead = pHead1;
        pMergedHead->next = Merge(pHead1->next, pHead2);
    } else {
        pMergedHead = pHead2;
        pMergedHead->next = Merge(pHead1, pHead2->next);
    }

    return pMergedHead;
}

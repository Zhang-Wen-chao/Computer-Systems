#include <iostream>

using namespace std;

// 定义链表结构
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 函数声明
ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2);

int main() {
    // 示例代码，创建两个链表，它们在节点3相交
    // List1: 1->2->3->6->7
    // List2: 4->5->3->6->7
    ListNode *common = new ListNode(3);
    common->next = new ListNode(6);
    common->next->next = new ListNode(7);

    ListNode *pHead1 = new ListNode(1);
    pHead1->next = new ListNode(2);
    pHead1->next->next = common;

    ListNode *pHead2 = new ListNode(4);
    pHead2->next = new ListNode(5);
    pHead2->next->next = common;

    ListNode *firstCommonNode = FindFirstCommonNode(pHead1, pHead2);
    if (firstCommonNode != nullptr) {
        cout << "The first common node is: " << firstCommonNode->val << endl;
    } else {
        cout << "No common node found." << endl;
    }

    // 清理内存，防止内存泄漏
    // 注意：这里仅删除了示例中创建的节点，实际使用时应根据实际情况来删除
    delete pHead1->next;
    delete pHead1;
    delete pHead2->next;
    delete pHead2;
    delete common->next->next;
    delete common->next;
    delete common;

    return 0;
}

// 函数定义
ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
    ListNode *p1 = pHead1;
    ListNode *p2 = pHead2;

    while (p1 != p2) {
        p1 = (p1 == nullptr) ? pHead2 : p1->next;
        p2 = (p2 == nullptr) ? pHead1 : p2->next;
    }

    return p1;
}

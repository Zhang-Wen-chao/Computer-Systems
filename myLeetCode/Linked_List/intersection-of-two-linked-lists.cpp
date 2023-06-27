// 面试题 02.07. 链表相交
// https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/

#include <iostream>
#include <vector>
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *tailA = headA;
        ListNode *tailB = headB;
        while (tailA->next != nullptr) {
            tailA = tailA->next;
        }
        while (tailB->next != nullptr) {
            tailB = tailB->next;
        }
        if (tailA != tailB) { // 两个链表不相交
            return nullptr;
        }
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while (p1 != p2) {
            p1 = (p1 == nullptr) ? headB : p1->next;
            p2 = (p2 == nullptr) ? headA : p2->next;
        }
        return p1; // 返回相交节点，如果没有相交节点则返回 nullptr。
    }
};

ListNode *constructLinkedList(std::vector<int> &vals) {
    ListNode *head = nullptr;
    ListNode *curr = nullptr;
    for (int val : vals) {
        if (head == nullptr) {
            head = new ListNode(val);
            curr = head;
        } else {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    // std::vector<int> A = {0,9,1,2,4};
    // std::vector<int> B = {3,2,4};

    std::vector<int> A = {4, 1, 8, 4, 5};
    std::vector<int> B = {5, 0, 1, 8, 4, 5};

    ListNode *headA = constructLinkedList(A);
    ListNode *headB = constructLinkedList(B);

    // 设置相交节点
    headB->next->next = headA->next->next;

    Solution sol;
    ListNode *intersection = sol.getIntersectionNode(headA, headB);
    if (intersection != nullptr) {
        std::cout << intersection->val << std::endl;
    } else {
        std::cout << "No intersection" << std::endl;
    }
    return 0;
}
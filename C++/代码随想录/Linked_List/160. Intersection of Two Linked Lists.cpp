// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

#include "LinkedListUtils.hpp"

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;
    
    ListNode* pA = headA;
    ListNode* pB = headB;
    
    while (pA != pB) {
        pA = pA ? pA->next : headB;
        pB = pB ? pB->next : headA;
    }
    
    return pA;
}

int main() {
    ListNode* headA = new ListNode(4);
    ListNode* node1 = new ListNode(1);
    ListNode* node8 = new ListNode(8);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    headA->next = node1;
    node1->next = node8;
    node8->next = node4;
    node4->next = node5;
    
    ListNode* headB = new ListNode(5);
    ListNode* node0 = new ListNode(0);
    ListNode* node1b = new ListNode(1);
    headB->next = node0;
    node0->next = node1b;
    node1b->next = node8; // Intersection point
    
    ListNode* intersection = getIntersectionNode(headA, headB);
    
    if (intersection != nullptr) {
        std::cout << "Intersection point: " << intersection->val << std::endl;
    } else {
        std::cout << "No intersection point found." << std::endl;
    }
    
    return 0;
}

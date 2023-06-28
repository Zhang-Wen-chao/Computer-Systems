// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

#include "LinkedListUtils.hpp"

ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr) {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7};
    ListNode *head = createLinkedList(values); 
    ListNode *reversed = reverseList(head);
    printList(reversed);

    return 0;
}

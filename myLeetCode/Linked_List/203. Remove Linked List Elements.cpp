// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/

#include "LinkedListUtils.hpp"

ListNode *removeElements(ListNode *head, int val) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;
    ListNode *curr = head;

    while (curr != nullptr) {
        if (curr->val == val) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return dummy.next;
}

int main() {
    std::vector<int> values = {1, 2, 6, 3, 4, 5, 6};
    ListNode *head = createLinkedList(values); 
    ListNode *result = removeElements(head, 6);
    printList(result);

    return 0;
}
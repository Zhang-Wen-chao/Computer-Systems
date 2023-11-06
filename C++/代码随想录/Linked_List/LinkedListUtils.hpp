#ifndef LINKEDLISTUTILS_HPP
#define LINKEDLISTUTILS_HPP

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* curr = nullptr;

    for (int val : values) {
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

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

#endif // LINKEDLISTUTILS_HPP

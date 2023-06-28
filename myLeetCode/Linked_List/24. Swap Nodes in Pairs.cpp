// 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/

#include "LinkedListUtils.hpp"

ListNode *swapPairs(ListNode *head) {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *temp = dummyHead;
    while (temp->next != nullptr && temp->next->next != nullptr) {
        ListNode *node1 = temp->next;
        ListNode *node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
    }
    ListNode *newHead = dummyHead->next;
    delete dummyHead; // 释放dummyHead内存
    return newHead;
}

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5, 6};
    ListNode* head = createLinkedList(values);
    ListNode *swapped = swapPairs(head);
    printList(swapped);

    // 释放链表内存
    ListNode *currNode = swapped;
    while (currNode) {
        ListNode *nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }

    return 0;
}

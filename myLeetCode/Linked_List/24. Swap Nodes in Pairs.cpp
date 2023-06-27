// 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/

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
};

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5, 6};
    ListNode *head = nullptr;
    ListNode *curr = nullptr;

    for (int val : values) {
        if (head == nullptr) {
            head = new ListNode(val);
            curr = head;
        } else {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
    }

    Solution sol;
    ListNode *swapped = sol.swapPairs(head);
    while (swapped) {
        std::cout << swapped->val << " ";
        swapped = swapped->next;
    }
    std::cout << std::endl;

    // 释放链表内存
    ListNode *currNode = swapped;
    while (currNode) {
        ListNode *nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }

    return 0;
}

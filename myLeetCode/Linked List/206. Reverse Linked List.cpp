// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode *reversed = sol.reverseList(head);

    while (reversed) {
        std::cout << reversed->val << " ";
        reversed = reversed->next;
    }
    std::cout << std::endl;

    return 0;
}

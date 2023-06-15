// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/

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
};

int main() {
    std::vector<int> values = {1, 2, 6, 3, 4, 5, 6};
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

    int target = 2;

    Solution sol;
    ListNode *result = sol.removeElements(head, target);

    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}
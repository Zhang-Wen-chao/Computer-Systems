// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(0, head);
        ListNode *fast = &dummy, *slow = &dummy;
        for (int i = 1; i <= n; ++i) {
            fast = fast->next;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy.next;
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
    ListNode *removed = sol.removeNthFromEnd(head, 2);
    while (removed) {
        std::cout << removed->val << " ";
        removed = removed->next;
    }
    std::cout << std::endl;
    return 0;
}

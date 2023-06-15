// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        // Step 1: Detect if there is a cycle
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        if (!fast || !fast->next) {
            return nullptr; // No cycle
        }

        // Step 2: Move one of the pointers to the head of the linked list
        slow = head;

        // Step 3: Move both pointers one step at a time until they meet again
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 4: Return the start of the cycle
        return slow;
    }
};

// Main function to test the solution
int main() {
    // Create a linked list with a cycle
    std::vector<int> values = {3, 2, 0, -4};
    ListNode *head = new ListNode(0);
    ListNode *cur = head;

    for (int val : values) {
        ListNode *node = new ListNode(val);
        cur->next = node;
        cur = node;
    }
    cur->next = head->next->next;

    // Create a solution object
    Solution sol;

    // Call the detectCycle method and print the result
    ListNode *node = sol.detectCycle(head);
    std::cout << node->val << std::endl; // Should print 2

    return 0;
}
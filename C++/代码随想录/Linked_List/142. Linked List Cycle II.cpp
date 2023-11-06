// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/

#include "LinkedListUtils.hpp"

ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {  // Cycle detected
            fast = head;  // Reset fast to head
            while (slow != fast) {  // Find the entry point of the cycle
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  // Return the entry point of the cycle
        }
    }
    return nullptr;  // No cycle
}

int main() {
    std::vector<int> values = {3, 2, 0, -4};
    ListNode *head = createLinkedList(values); 
    // 设置链表的最后一个节点的 next 指针，形成环
    ListNode *cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = head->next;

    ListNode *node = detectCycle(head);
    std::cout << node->val << std::endl; // Should print 2

    return 0;
}
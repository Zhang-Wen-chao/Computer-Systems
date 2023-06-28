// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/

#include "LinkedListUtils.hpp"

ListNode *detectCycle(ListNode *head) {
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

    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
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
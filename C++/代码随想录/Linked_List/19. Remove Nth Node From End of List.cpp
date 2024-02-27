// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include "LinkedListUtils.hpp"

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // 先将 fast 指针移动 n+1 步
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // 同时移动 fast 和 slow 指针，直到 fast 到达链表末尾
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // 删除 slow 指针后的节点
    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return dummy->next;
}

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7};
    ListNode* head = createLinkedList(values);
    ListNode* removed = removeNthFromEnd(head, 2);
    printList(removed);

    return 0;
}

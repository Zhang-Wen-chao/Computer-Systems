from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        current = head
        while current:
            next_temp = current.next
            current.next = prev
            prev = current
            current = next_temp
        return prev

def printList(head):
    values = []
    while head:
        values.append(head.val)
        head = head.next
    return values

sol = Solution()

# 创建一个链表 [1, 2, 3, 4, 5]
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))

# 反转链表
print(printList(sol.reverseList(head)))  # 应该输出 [5, 4, 3, 2, 1]

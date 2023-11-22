from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        first = second = dummy
        for _ in range(n + 1):
            first = first.next

        while first:
            first = first.next
            second = second.next

        second.next = second.next.next
        return dummy.next

# 测试用例
def printList(head):
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("None")

sol = Solution()

# 创建链表 1 -> 2 -> 3 -> 4 -> 5
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))

# 删除倒数第二个节点
printList(sol.removeNthFromEnd(head, 2))  # 应该输出 1 -> 2 -> 3 -> 5 -> None

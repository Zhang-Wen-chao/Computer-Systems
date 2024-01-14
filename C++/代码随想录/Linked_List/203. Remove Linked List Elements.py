from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        current = dummy

        while current.next:
            if current.next.val == val:
                current.next = current.next.next
            else:
                current = current.next

        return dummy.next

# 测试用例
def printList(head):
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("None")

sol = Solution()

# 创建链表 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
head = ListNode(1, ListNode(2, ListNode(6, ListNode(3, ListNode(4, ListNode(5, ListNode(6)))))))

# 移除值为 6 的节点
printList(sol.removeElements(head, 6))  # 应该输出 1 -> 2 -> 3 -> 4 -> 5 -> None

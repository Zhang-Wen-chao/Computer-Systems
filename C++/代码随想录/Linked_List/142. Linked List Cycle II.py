from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None

        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break

        if not fast or not fast.next:
            return None

        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next

        return slow

sol = Solution()

# 创建一个有环的链表 [3,2,0,-4]，环的入口是节点 2
cycle_list = ListNode(3, ListNode(2, ListNode(0, ListNode(-4))))
cycle_list.next.next.next.next = cycle_list.next

cycle_node = sol.detectCycle(cycle_list)
print(cycle_node.val if cycle_node else "No cycle")  # 应该输出 2
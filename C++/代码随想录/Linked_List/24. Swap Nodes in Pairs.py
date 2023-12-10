from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        prev_node = dummy

        while head and head.next:
            # 节点初始化
            first_node = head
            second_node = head.next

            # 交换
            prev_node.next = second_node
            first_node.next = second_node.next
            second_node.next = first_node

            # 重新初始化 prev_node 和 head
            prev_node = first_node
            head = first_node.next

        return dummy.next

# 测试用例
def printList(head):
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("None")

sol = Solution()

# 创建链表 1 -> 2 -> 3 -> 4
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))

# 交换节点
printList(sol.swapPairs(head))  # 应该输出 2 -> 1 -> 4 -> 3 -> None

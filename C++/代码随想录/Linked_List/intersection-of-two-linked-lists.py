class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None

        pointerA, pointerB = headA, headB
        
        while pointerA != pointerB:
            pointerA = pointerA.next if pointerA else headB
            pointerB = pointerB.next if pointerB else headA

        return pointerA

sol = Solution()

# 测试用例
# 创建两个链表：A: 1->2->3->4->5 和 B: 6->7->8->3->4->5 (相交于节点3)
shared = ListNode(3, ListNode(4, ListNode(5)))
listA = ListNode(1, ListNode(2, shared))
listB = ListNode(6, ListNode(7, ListNode(8, shared)))

print(sol.getIntersectionNode(listA, listB).val)
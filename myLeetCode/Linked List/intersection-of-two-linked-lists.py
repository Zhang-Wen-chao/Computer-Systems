# 面试题 02.07. 链表相交
# https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if headA is None or headB is None:
            return None
        
        tailA = headA
        tailB = headB
        while tailA.next is not None:
            tailA = tailA.next
        while tailB.next is not None:
            tailB = tailB.next
        
        if tailA != tailB:
            return None
        
        p1 = headA
        p2 = headB
        while p1 != p2:
            p1 = headB if p1 is None else p1.next
            p2 = headA if p2 is None else p2.next
        
        return p1

def constructLinkedList(vals):
    head = None
    curr = None
    for val in vals:
        if head is None:
            head = ListNode(val)
            curr = head
        else:
            curr.next = ListNode(val)
            curr = curr.next
    return head

def main():
    A = [4, 1, 8, 4, 5]
    B = [5, 0, 1, 8, 4, 5]

    headA = constructLinkedList(A)
    headB = constructLinkedList(B)

    # 设置相交节点
    headB.next.next = headA.next.next

    sol = Solution()
    intersection = sol.getIntersectionNode(headA, headB)
    if intersection is not None:
        print(intersection.val)
    else:
        print("No intersection")

if __name__ == "__main__":
    main()
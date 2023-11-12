class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def getIntersectionNode(headA, headB):
    if not headA or not headB:
        return None

    pointerA, pointerB = headA, headB

    while pointerA != pointerB:
        pointerA = pointerA.next if pointerA else headB
        pointerB = pointerB.next if pointerB else headA

    return pointerA

# 测试用例
# 创建两个链表：A: 1->2->3->4->5 和 B: 6->7->8->3->4->5 (相交于节点3)
node1 = ListNode(1)
node2 = ListNode(2)
node3 = ListNode(3)
node4 = ListNode(4)
node5 = ListNode(5)
node6 = ListNode(6)
node7 = ListNode(7)
node8 = ListNode(8)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node5

node6.next = node7
node7.next = node8
node8.next = node3

print(getIntersectionNode(node1, node6).val)  # 应输出3

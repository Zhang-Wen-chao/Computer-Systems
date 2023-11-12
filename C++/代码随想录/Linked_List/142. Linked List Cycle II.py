class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def detectCycle(head):
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

# 测试用例
def createCycleList(values, pos):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    cycle_entry = None
    for i in range(1, len(values)):
        current.next = ListNode(values[i])
        current = current.next
        if i == pos:
            cycle_entry = current
    if pos != -1:
        current.next = cycle_entry
    return head

# 创建一个有环的链表 [3,2,0,-4]，环的入口是节点 2
cycle_list = createCycleList([3, 2, 0, -4], 1)
cycle_node = detectCycle(cycle_list)
print(cycle_node.val if cycle_node else "No cycle")  # 应该输出 2

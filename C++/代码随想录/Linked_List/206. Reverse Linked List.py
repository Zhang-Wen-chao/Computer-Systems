class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverseList(head):
    prev = None
    current = head
    while current:
        next_temp = current.next
        current.next = prev
        prev = current
        current = next_temp
    return prev

# 测试用例
def createList(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next
    return head

def printList(head):
    values = []
    while head:
        values.append(head.val)
        head = head.next
    return values

# 创建一个链表 [1, 2, 3, 4, 5]
list_head = createList([1, 2, 3, 4, 5])
# 反转链表
reversed_list = reverseList(list_head)
# 打印反转后的链表
print(printList(reversed_list))  # 应该输出 [5, 4, 3, 2, 1]

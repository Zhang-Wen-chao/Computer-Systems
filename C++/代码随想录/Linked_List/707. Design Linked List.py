class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class MyLinkedList:
    def __init__(self):
        self.size = 0
        self.head = ListNode(0)  # 虚拟头节点

    def get(self, index: int) -> int:
        if index < 0 or index >= self.size:
            return -1
        current = self.head
        for _ in range(index + 1):
            current = current.next
        return current.val

    def addAtHead(self, val: int) -> None:
        self.addAtIndex(0, val)

    def addAtTail(self, val: int) -> None:
        self.addAtIndex(self.size, val)

    def addAtIndex(self, index: int, val: int) -> None:
        if index > self.size:
            return
        if index < 0:
            index = 0
        self.size += 1
        pred = self.head
        for _ in range(index):
            pred = pred.next
        to_add = ListNode(val)
        to_add.next = pred.next
        pred.next = to_add

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.size:
            return
        self.size -= 1
        pred = self.head
        for _ in range(index):
            pred = pred.next
        pred.next = pred.next.next

# 测试用例
linked_list = MyLinkedList()
linked_list.addAtHead(1)
linked_list.addAtTail(3)
linked_list.addAtIndex(1, 2)  # 链表变为1->2->3
print(linked_list.get(1))     # 返回2
linked_list.deleteAtIndex(1)  # 现在链表是1->3
print(linked_list.get(1))     # 返回3

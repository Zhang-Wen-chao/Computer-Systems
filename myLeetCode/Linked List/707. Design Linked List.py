# 707. Design Linked List
# https://leetcode.com/problems/design-linked-list/

from collections import deque

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class MyLinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def get(self, index: int) -> int:
        if index < 0 or index >= self.size:
            return -1

        curr = self.head
        for _ in range(index):
            curr = curr.next

        return curr.val

    def addAtHead(self, val: int) -> None:
        newNode = ListNode(val)
        newNode.next = self.head
        self.head = newNode
        self.size += 1

    def addAtTail(self, val: int) -> None:
        newNode = ListNode(val)
        if self.head is None:
            self.head = newNode
        else:
            curr = self.head
            while curr.next:
                curr = curr.next
            curr.next = newNode
        self.size += 1

    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0 or index > self.size:
            return

        if index == 0:
            self.addAtHead(val)
            return

        newNode = ListNode(val)
        curr = self.head
        for _ in range(index - 1):
            curr = curr.next
        newNode.next = curr.next
        curr.next = newNode
        self.size += 1

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.size:
            return

        if index == 0:
            self.head = self.head.next
            self.size -= 1
            return

        curr = self.head
        for _ in range(index - 1):
            curr = curr.next
        curr.next = curr.next.next
        self.size -= 1

    def printLinkedList(self) -> None:
        curr = self.head
        while curr:
            print(curr.val, end=" ")
            curr = curr.next
        print()

linkedList = MyLinkedList()
linkedList.addAtHead(1)
linkedList.addAtTail(3)
linkedList.addAtIndex(1, 2)
print(linkedList.get(1))
linkedList.deleteAtIndex(1)
print(linkedList.get(1))
linkedList.printLinkedList()

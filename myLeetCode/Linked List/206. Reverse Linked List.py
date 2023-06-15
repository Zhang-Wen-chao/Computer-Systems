# 206. Reverse Linked List
# https://leetcode.com/problems/reverse-linked-list/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        curr = head
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        return prev

def main():
    values = [1, 2, 3, 4, 5, 6]
    head = None
    curr = None

    for val in values:
        if head is None:
            head = ListNode(val)
            curr = head
        else:
            curr.next = ListNode(val)
            curr = curr.next

    # Reverse the linked list
    sol = Solution()
    reversed = sol.reverseList(head)

    # Print the reversed linked list
    while reversed:
        print(reversed.val, end=" ")
        reversed = reversed.next
    print()

if __name__ == "__main__":
    main()
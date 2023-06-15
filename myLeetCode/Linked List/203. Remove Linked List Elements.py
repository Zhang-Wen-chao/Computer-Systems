# 203. Remove Linked List Elements
# https://leetcode.com/problems/remove-linked-list-elements/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        curr = head

        while curr:
            if curr.val == val:
                prev.next = curr.next
                curr = curr.next
            else:
                prev = curr
                curr = curr.next

        return dummy.next

def main():
    values = [1, 2, 6, 3, 4, 5, 6]
    head = None
    curr = None

    for val in values:
        if head is None:
            head = ListNode(val)
            curr = head
        else:
            curr.next = ListNode(val)
            curr = curr.next

    target = 6

    sol = Solution()
    result = sol.removeElements(head, target)

    # 遍历链表并打印值
    while result:
        print(result.val, end=" ")
        result = result.next
    print()

if __name__ == "__main__":
    main()
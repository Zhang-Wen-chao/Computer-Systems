# 19. Remove Nth Node From End of List
# https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0, head)
        fast, slow = dummy, dummy
        
        for i in range(n):
            fast = fast.next
        
        while fast.next is not None:
            fast = fast.next
            slow = slow.next
            
        to_delete = slow.next
        slow.next = slow.next.next
        del to_delete
        
        return dummy.next

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

    sol = Solution()
    removed = sol.removeNthFromEnd(head, 2)
    while removed:
        print(removed.val, end=' ')
        removed = removed.next
    print()

if __name__ == "__main__":
    main()
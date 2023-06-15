# 142. Linked List Cycle II
# https://leetcode.com/problems/linked-list-cycle-ii/

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        # Step 1: Detect if there is a cycle
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break
        else:
            return None # No cycle
        
        # Step 2: Move one of the pointers to the head of the linked list
        slow = head
        
        # Step 3: Move both pointers one step at a time until they meet again
        while slow != fast:
            slow = slow.next
            fast = fast.next
        
        # Step 4: Return the start of the cycle
        return slow

# Main function to test the solution
def main():
    # Create an array of node values
    values = [3, 2, 0, -4]
    head = ListNode(0)
    cur = head
    for val in values:
        node = ListNode(val)
        cur.next = node
        cur = node
    # Link the last node to the second node to form a cycle
    cur.next = head.next.next

    
    # Create a solution object
    sol = Solution()
    
    # Call the detectCycle method and print the result
    node = sol.detectCycle(head)
    print(node.val) # Should print 2

if __name__ == "__main__":
    main()

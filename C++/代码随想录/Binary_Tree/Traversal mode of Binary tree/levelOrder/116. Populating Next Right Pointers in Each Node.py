# 116. Populating Next Right Pointers in Each Node
# https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

# 117. Populating Next Right Pointers in Each Node II
# https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

# 这两道题的代码完全一样。
class Node:
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return None

        leftmost = root
        while leftmost:
            dummy = Node(0)
            tail = dummy
            cur = leftmost

            while cur:
                if cur.left:
                    tail.next = cur.left
                    tail = tail.next
                if cur.right:
                    tail.next = cur.right
                    tail = tail.next
                cur = cur.next

            leftmost = dummy.next

        return root

# Test case
root = Node(1, Node(2, Node(4), Node(5)), Node(3, Node(6), Node(7)))
sol = Solution()
print(sol.connect(root))  # Connects the nodes as described in the problem statement

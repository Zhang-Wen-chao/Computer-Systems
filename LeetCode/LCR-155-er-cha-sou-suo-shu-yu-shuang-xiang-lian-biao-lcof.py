# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:
            return None

        # Initialize previous and head pointers
        self.head = None
        self.prev = None

        # Helper function to perform in-order traversal
        def inorder(node):
            if not node:
                return
            
            # Recursively traverse the left subtree
            inorder(node.left)
            
            # If prev is None, this is the first node (smallest)
            if self.prev:
                # Link the previous node (prev) with the current one (node)
                self.prev.right = node
                node.left = self.prev
            else:
                # Keep track of the smallest node as head
                self.head = node
            
            # Update prev to the current node
            self.prev = node
            
            # Recursively traverse the right subtree
            inorder(node.right)
        
        # Perform in-order traversal and link nodes
        inorder(root)
        
        # Complete the circular linking
        self.head.left = self.prev
        self.prev.right = self.head

        return self.head

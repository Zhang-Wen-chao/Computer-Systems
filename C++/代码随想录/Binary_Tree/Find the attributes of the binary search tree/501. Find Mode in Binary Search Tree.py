from typing import Optional
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        def inorder(node):
            nonlocal max_count, current_count, current_val
            if node:
                inorder(node.left)
                if node.val != current_val:
                    current_val = node.val
                    current_count = 0
                current_count += 1
                if current_count == max_count:
                    modes.append(node.val)
                elif current_count > max_count:
                    max_count = current_count
                    modes.clear()
                    modes.append(node.val)
                inorder(node.right)

        max_count = current_count = 0
        current_val = None
        modes = []
        inorder(root)
        return modes

# Test case
root = TreeNode(1, None, TreeNode(2, TreeNode(2)))
sol = Solution()
print(sol.findMode(root))  # [2]

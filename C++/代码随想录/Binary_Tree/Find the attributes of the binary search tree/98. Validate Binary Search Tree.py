from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def validate(node, low=float('-inf'), high=float('inf')):
            if not node:
                return True
            if node.val <= low or node.val >= high:
                return False
            return validate(node.right, node.val, high) and validate(node.left, low, node.val)
        
        return validate(root)

# Test case
root = TreeNode(2, TreeNode(1), TreeNode(3))
sol = Solution()
print(sol.isValidBST(root))  # True

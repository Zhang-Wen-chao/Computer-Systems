from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        def inorder(node):
            nonlocal prev, min_diff
            if node:
                inorder(node.left)
                if prev is not None:
                    min_diff = min(min_diff, node.val - prev)
                prev = node.val
                inorder(node.right)
        
        prev = None
        min_diff = float('inf')
        inorder(root)
        return min_diff

# Test case
root = TreeNode(4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(6))
sol = Solution()
print(sol.getMinimumDifference(root))  # 1

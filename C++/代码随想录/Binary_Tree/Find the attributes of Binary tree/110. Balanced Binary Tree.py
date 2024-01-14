from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def check(node):
            if not node:
                return 0, True
            left_height, left_balanced = check(node.left)
            right_height, right_balanced = check(node.right)
            return max(left_height, right_height) + 1, left_balanced and right_balanced and abs(left_height - right_height) <= 1
        
        return check(root)[1]

# Test case
root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
sol = Solution()
print(sol.isBalanced(root))  # True

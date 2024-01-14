from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def isMirror(left, right):
            if not left and not right:
                return True
            if not left or not right:
                return False
            return (left.val == right.val) and isMirror(left.right, right.left) and isMirror(left.left, right.right)

        return isMirror(root, root)

# Test case
root = TreeNode(1, TreeNode(2, TreeNode(3), TreeNode(4)), TreeNode(2, TreeNode(4), TreeNode(3)))
sol = Solution()
print(sol.isSymmetric(root))  # True

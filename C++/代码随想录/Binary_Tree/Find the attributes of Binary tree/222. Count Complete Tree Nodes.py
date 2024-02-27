from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        left_depth = self.getDepth(root.left)
        right_depth = self.getDepth(root.right)
        if left_depth == right_depth:
            return (1 << left_depth) + self.countNodes(root.right)
        else:
            return (1 << right_depth) + self.countNodes(root.left)
    
    def getDepth(self, node):
        depth = 0
        while node:
            depth += 1
            node = node.left
        return depth

# Test case
root = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3, TreeNode(6)))
sol = Solution()
print(sol.countNodes(root))  # 6

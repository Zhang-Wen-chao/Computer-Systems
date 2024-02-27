from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        if not root:
            return None
        if root.val < low:
            return self.trimBST(root.right, low, high)
        if root.val > high:
            return self.trimBST(root.left, low, high)
        root.left = self.trimBST(root.left, low, high)
        root.right = self.trimBST(root.right, low, high)
        return root

# Test case
root = TreeNode(3, TreeNode(0, None, TreeNode(2, TreeNode(1))), TreeNode(4))
sol = Solution()
trimmed_tree = sol.trimBST(root, 1, 3)

def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []
print(inorder_traversal(trimmed_tree))  # [1, 2, 3]

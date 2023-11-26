from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root:
            return None
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            if not root.left:
                return root.right
            if not root.right:
                return root.left
            temp = root.right
            minVal = temp.val
            while temp.left:
                temp = temp.left
                minVal = temp.val
            root.val = minVal
            root.right = self.deleteNode(root.right, root.val)
        return root

# Test case
root = TreeNode(5, TreeNode(3, TreeNode(2), TreeNode(4)), TreeNode(6, None, TreeNode(7)))
sol = Solution()
updated_tree = sol.deleteNode(root, 3)

# 测试用例
def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []
print(inorder_traversal(updated_tree)) # [2, 4, 5, 6, 7]

from typing import List
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not inorder or not postorder:
            return None
        
        root = TreeNode(postorder.pop())
        mid = inorder.index(root.val)
        root.right = self.buildTree(inorder[mid+1:], postorder)
        root.left = self.buildTree(inorder[:mid], postorder)
        return root



inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
sol = Solution()
tree = sol.buildTree(inorder, postorder)

# 打印用例
def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []
print(inorder_traversal(tree))  # [9, 3, 15, 20, 7]

from typing import Optional
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        return [root.val] + self.preorderTraversal(root.left) + self.preorderTraversal(root.right) if root else []

sol = Solution()

# 测试用例
root = TreeNode(1, None, TreeNode(2, TreeNode(3)))
print(sol.preorderTraversal(root))  # 应输出 [1, 2, 3]

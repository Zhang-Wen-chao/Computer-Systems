from typing import List
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        if not nums:
            return None
        max_val = max(nums)
        max_index = nums.index(max_val)
        root = TreeNode(max_val)
        root.left = self.constructMaximumBinaryTree(nums[:max_index])
        root.right = self.constructMaximumBinaryTree(nums[max_index+1:])
        return root

# Test case
nums = [3,2,1,6,0,5]
sol = Solution()
tree = sol.constructMaximumBinaryTree(nums)

# 打印用例
def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []
print(inorder_traversal(tree))  # [5, 4, 4, 3, 5, 7]
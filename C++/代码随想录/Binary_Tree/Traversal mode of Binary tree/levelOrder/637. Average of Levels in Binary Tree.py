from collections import deque
from typing import List
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        res = []
        queue = deque([root])
        while queue:
            level_sum = 0
            level_count = len(queue)
            for _ in range(level_count):
                node = queue.popleft()
                level_sum += node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            res.append(level_sum / level_count)
        return res

# Test case
root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
sol = Solution()
print(sol.averageOfLevels(root))  # [3.0, 14.5, 11.0]

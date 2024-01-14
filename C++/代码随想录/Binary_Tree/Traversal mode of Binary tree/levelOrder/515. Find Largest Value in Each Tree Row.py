from collections import deque
from typing import List
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        res = []
        queue = deque([root])
        while queue:
            level_max = float('-inf')
            for _ in range(len(queue)):
                node = queue.popleft()
                level_max = max(level_max, node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            res.append(level_max)
        return res

# Test case
root = TreeNode(1, TreeNode(3, TreeNode(5), TreeNode(3)), TreeNode(2, None, TreeNode(9)))
sol = Solution()
print(sol.largestValues(root))  # [1, 3, 9]

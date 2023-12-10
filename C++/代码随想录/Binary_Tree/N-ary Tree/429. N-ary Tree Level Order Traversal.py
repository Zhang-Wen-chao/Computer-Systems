from collections import deque
from typing import List

class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []
        result = []
        queue = deque([root])
        while queue:
            level = []
            for _ in range(len(queue)):
                node = queue.popleft()
                level.append(node.val)
                for child in node.children:
                    queue.append(child)
            result.append(level)
        return result

# Test case
root = Node(1, [Node(3, [Node(5), Node(6)]), Node(2), Node(4)])
sol = Solution()
print(sol.levelOrder(root))  # [[1], [3, 2, 4], [5, 6]]
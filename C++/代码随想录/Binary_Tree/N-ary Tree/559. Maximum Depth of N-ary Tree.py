class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
        depth = 0
        for child in root.children:
            depth = max(depth, self.maxDepth(child))
        return depth + 1

# Test case
root = Node(1, [Node(3, [Node(5), Node(6)]), Node(2), Node(4)])
sol = Solution()
print(sol.maxDepth(root))  # 3
from typing import List

class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if not root:
            return []
        
        result = [root.val]
        for child in root.children:
            result.extend(self.preorder(child))
        return result

# Test case
root = Node(1, [Node(3, [Node(5), Node(6)]), Node(2), Node(4)])
sol = Solution()
print(sol.preorder(root))  # [1, 3, 5, 6, 2, 4]
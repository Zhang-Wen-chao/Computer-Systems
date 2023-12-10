from typing import List

class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if not root:
            return []
        
        result = []
        for child in root.children:
            result.extend(self.postorder(child))
        result.append(root.val)
        return result

# Test case
root = Node(1, [Node(3, [Node(5), Node(6)]), Node(2), Node(4)])
sol = Solution()
print(sol.postorder(root))  # [5, 6, 3, 2, 4, 1]
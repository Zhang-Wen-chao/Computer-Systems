class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

def maxDepth(root):
    if not root:
        return 0

    depth = 0
    for child in root.children:
        depth = max(depth, maxDepth(child))
    return depth + 1

# 测试用例
root = Node(1, [Node(3, [Node(5), Node(6)]), Node(2), Node(4)])
print(maxDepth(root))  # 应输出 3

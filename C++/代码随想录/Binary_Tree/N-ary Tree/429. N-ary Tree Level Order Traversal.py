class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

def levelOrder(root):
    if not root:
        return []

    result = []
    queue = [root]

    while queue:
        level = []
        for _ in range(len(queue)):
            node = queue.pop(0)
            level.append(node.val)
            queue.extend(node.children)
        result.append(level)

    return result

# 测试用例
root = Node(1, [Node(3, [Node(5), Node(6)]), Node(2), Node(4)])
print(levelOrder(root))  # [[1], [3, 2, 4], [5, 6]]

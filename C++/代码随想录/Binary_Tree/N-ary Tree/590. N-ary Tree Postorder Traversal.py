class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

def postorder(root):
    if not root:
        return []
    
    result = []
    for child in root.children:
        result.extend(postorder(child))
    result.append(root.val)
    return result

# 测试用例
root = Node(1, [Node(3, [Node(5), Node(6)]), Node(2), Node(4)])
print(postorder(root))  # 应输出 [5, 6, 3, 2, 4, 1]

class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

def preorder(root):
    if not root:
        return []
    
    result = [root.val]
    for child in root.children:
        result.extend(preorder(child))
    return result

# 测试用例
root = Node(1, [Node(3, [Node(5), Node(6)]), Node(2), Node(4)])
print(preorder(root))  # 应输出 [1, 3, 5, 6, 2, 4]

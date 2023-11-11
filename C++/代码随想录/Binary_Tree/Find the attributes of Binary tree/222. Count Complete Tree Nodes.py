class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def countNodes(root):
    if not root:
        return 0
    left_depth = get_depth(root.left)
    right_depth = get_depth(root.right)
    if left_depth == right_depth:
        return (1 << left_depth) + countNodes(root.right)
    else:
        return (1 << right_depth) + countNodes(root.left)

def get_depth(node):
    depth = 0
    while node:
        depth += 1
        node = node.left
    return depth

# 测试用例
tree1 = TreeNode(1)
tree1.left = TreeNode(2)
tree1.right = TreeNode(3)
tree1.left.left = TreeNode(4)
tree1.left.right = TreeNode(5)
tree1.right.left = TreeNode(6)

print(countNodes(tree1))  # 6

tree2 = TreeNode(1)
tree2.left = TreeNode(2)
tree2.right = TreeNode(3)
tree2.left.left = TreeNode(4)
tree2.left.right = TreeNode(5)

print(countNodes(tree2))  # 5

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def invertTree(root):
    if root:
        root.left, root.right = invertTree(root.right), invertTree(root.left)
    return root

# 测试用例
def preorder_traversal(root):
    return [root.val] + preorder_traversal(root.left) + preorder_traversal(root.right) if root else []

# 构建测试树
root = TreeNode(4)
root.left = TreeNode(2)
root.left.left = TreeNode(1)
root.left.right = TreeNode(3)
root.right = TreeNode(7)
root.right.left = TreeNode(6)
root.right.right = TreeNode(9)

# 翻转树并输出前序遍历结果
inverted_tree = invertTree(root)
print(preorder_traversal(inverted_tree))  # [4, 7, 9, 6, 2, 3, 1]

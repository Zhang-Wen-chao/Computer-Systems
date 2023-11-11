class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def maxDepth(root):
    if not root:
        return 0
    else:
        left_height = maxDepth(root.left)
        right_height = maxDepth(root.right)
        return max(left_height, right_height) + 1

# 测试用例
tree = TreeNode(3)
tree.left = TreeNode(9)
tree.right = TreeNode(20)
tree.right.left = TreeNode(15)
tree.right.right = TreeNode(7)

print(maxDepth(tree))  # 3

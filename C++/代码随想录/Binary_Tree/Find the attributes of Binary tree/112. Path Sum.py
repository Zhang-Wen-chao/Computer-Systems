class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def hasPathSum(root, sum):
    if not root:
        return False
    if not root.left and not root.right and root.val == sum:
        return True
    return hasPathSum(root.left, sum - root.val) or hasPathSum(root.right, sum - root.val)

# 测试用例
tree1 = TreeNode(5)
tree1.left = TreeNode(4)
tree1.right = TreeNode(8)
tree1.left.left = TreeNode(11)
tree1.left.left.left = TreeNode(7)
tree1.left.left.right = TreeNode(2)
tree1.right.left = TreeNode(13)
tree1.right.right = TreeNode(4)
tree1.right.right.right = TreeNode(1)

print(hasPathSum(tree1, 22))  # True

tree2 = TreeNode(1)
tree2.left = TreeNode(2)
tree2.right = TreeNode(3)

print(hasPathSum(tree2, 5))  # False

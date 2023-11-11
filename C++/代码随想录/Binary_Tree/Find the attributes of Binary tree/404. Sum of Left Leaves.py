class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def sumOfLeftLeaves(root):
    if not root:
        return 0
    return dfs(root, False)

def dfs(node, isLeft):
    if not node:
        return 0
    if not node.left and not node.right and isLeft:
        return node.val
    return dfs(node.left, True) + dfs(node.right, False)

# 测试用例
tree1 = TreeNode(3)
tree1.left = TreeNode(9)
tree1.right = TreeNode(20)
tree1.right.left = TreeNode(15)
tree1.right.right = TreeNode(7)

print(sumOfLeftLeaves(tree1))  # 24

tree2 = TreeNode(1)
tree2.left = TreeNode(2)
tree2.right = TreeNode(3)
tree2.left.left = TreeNode(4)
tree2.left.right = TreeNode(5)

print(sumOfLeftLeaves(tree2))  # 4

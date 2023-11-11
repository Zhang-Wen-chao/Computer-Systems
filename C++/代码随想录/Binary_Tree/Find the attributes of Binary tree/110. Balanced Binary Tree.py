class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isBalanced(root):
    def check(root):
        if not root:
            return 0
        left = check(root.left)
        right = check(root.right)
        if left == -1 or right == -1 or abs(left - right) > 1:
            return -1
        return max(left, right) + 1

    return check(root) != -1

# 测试用例
tree1 = TreeNode(3)
tree1.left = TreeNode(9)
tree1.right = TreeNode(20)
tree1.right.left = TreeNode(15)
tree1.right.right = TreeNode(7)

tree2 = TreeNode(1)
tree2.left = TreeNode(2)
tree2.right = TreeNode(2)
tree2.left.left = TreeNode(3)
tree2.left.right = TreeNode(3)
tree2.left.left.left = TreeNode(4)
tree2.left.left.right = TreeNode(4)

print(isBalanced(tree1))  # True
print(isBalanced(tree2))  # False

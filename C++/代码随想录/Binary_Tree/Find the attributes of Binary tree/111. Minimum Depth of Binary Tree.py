class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def minDepth(root):
    if not root:
        return 0
    if not root.left and not root.right:
        return 1
    if not root.left:
        return minDepth(root.right) + 1
    if not root.right:
        return minDepth(root.left) + 1
    return min(minDepth(root.left), minDepth(root.right)) + 1

# 测试用例
tree1 = TreeNode(3)
tree1.left = TreeNode(9)
tree1.right = TreeNode(20)
tree1.right.left = TreeNode(15)
tree1.right.right = TreeNode(7)

tree2 = TreeNode(2)
tree2.right = TreeNode(3)
tree2.right.right = TreeNode(4)
tree2.right.right.right = TreeNode(5)
tree2.right.right.right.right = TreeNode(6)

print(minDepth(tree1))  # 2
print(minDepth(tree2))  # 5

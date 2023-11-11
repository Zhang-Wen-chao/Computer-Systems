class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def getMinimumDifference(root):
    def inorder(node):
        if node:
            inorder(node.left)
            if inorder.prev is not None:
                inorder.min_diff = min(inorder.min_diff, node.val - inorder.prev)
            inorder.prev = node.val
            inorder(node.right)

    inorder.prev = None
    inorder.min_diff = float('inf')
    inorder(root)
    return inorder.min_diff

# 测试用例
root = TreeNode(1)
root.right = TreeNode(3)
root.right.left = TreeNode(2)

print(getMinimumDifference(root))  # 1

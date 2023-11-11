class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isValidBST(root):
    def validate(node, low=-float('inf'), high=float('inf')):
        if not node:
            return True
        if node.val <= low or node.val >= high:
            return False
        return validate(node.right, node.val, high) and validate(node.left, low, node.val)

    return validate(root)

# 测试用例
root1 = TreeNode(2)
root1.left = TreeNode(1)
root1.right = TreeNode(3)
print(isValidBST(root1))  # True

root2 = TreeNode(5)
root2.left = TreeNode(1)
root2.right = TreeNode(4)
root2.right.left = TreeNode(3)
root2.right.right = TreeNode(6)
print(isValidBST(root2))  # False

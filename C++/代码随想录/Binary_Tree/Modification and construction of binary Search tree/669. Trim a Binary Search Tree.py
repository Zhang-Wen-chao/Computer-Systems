class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def trimBST(root, low, high):
    if not root:
        return None

    if root.val < low:
        return trimBST(root.right, low, high)
    elif root.val > high:
        return trimBST(root.left, low, high)
    else:
        root.left = trimBST(root.left, low, high)
        root.right = trimBST(root.right, low, high)
        return root

# 测试用例
def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []

root = TreeNode(3, TreeNode(0, None, TreeNode(2, TreeNode(1))), TreeNode(4))
trimmed_root = trimBST(root, 1, 3)
print(inorder_traversal(trimmed_root))  # [1, 2, 3]

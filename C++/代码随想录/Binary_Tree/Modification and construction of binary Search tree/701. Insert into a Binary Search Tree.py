class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def insertIntoBST(root, val):
    if not root:
        return TreeNode(val)

    if val < root.val:
        root.left = insertIntoBST(root.left, val)
    else:
        root.right = insertIntoBST(root.right, val)

    return root

# 测试用例
def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []

root = TreeNode(4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(7))
insertIntoBST(root, 5)
print(inorder_traversal(root))  # [1, 2, 3, 4, 5, 7]

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def deleteNode(root, key):
    if not root:
        return None

    if key < root.val:
        root.left = deleteNode(root.left, key)
    elif key > root.val:
        root.right = deleteNode(root.right, key)
    else:
        if not root.left:
            return root.right
        if not root.right:
            return root.left

        temp = root.right
        mini = temp.val
        while temp.left:
            temp = temp.left
            mini = temp.val

        root.val = mini
        root.right = deleteNode(root.right, root.val)

    return root

# 测试用例
def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []

root = TreeNode(5, TreeNode(3, TreeNode(2), TreeNode(4)), TreeNode(6, None, TreeNode(7)))
root = deleteNode(root, 3)
print(inorder_traversal(root))  # [2, 4, 5, 6, 7]

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def searchBST(root, val):
    if root is None or root.val == val:
        return root
    elif val < root.val:
        return searchBST(root.left, val)
    else:
        return searchBST(root.right, val)

# 测试用例
root = TreeNode(4)
root.left = TreeNode(2)
root.right = TreeNode(7)
root.left.left = TreeNode(1)
root.left.right = TreeNode(3)

result = searchBST(root, 2)

# 函数来打印树的中序遍历结果
def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []

print(inorder_traversal(result))  # [1, 2, 3]

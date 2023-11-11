class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def convertBST(root):
    def reverse_inorder(node, acc_sum):
        if node:
            acc_sum = reverse_inorder(node.right, acc_sum)
            node.val += acc_sum
            acc_sum = node.val
            acc_sum = reverse_inorder(node.left, acc_sum)
        return acc_sum

    reverse_inorder(root, 0)
    return root

# 测试用例
root = TreeNode(4)
root.left = TreeNode(1)
root.right = TreeNode(6)
root.left.left = TreeNode(0)
root.left.right = TreeNode(2)
root.left.right.right = TreeNode(3)
root.right.left = TreeNode(5)
root.right.right = TreeNode(7)
root.right.right.right = TreeNode(8)

converted_root = convertBST(root)

# 函数来打印树的中序遍历结果
def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []

print(inorder_traversal(converted_root))  # [36, 36, 35, 33, 30, 26, 21, 15, 8]

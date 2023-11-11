class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def mergeTrees(t1, t2):
    if not t1 and not t2:
        return None
    val1 = t1.val if t1 else 0
    val2 = t2.val if t2 else 0
    new_root = TreeNode(val1 + val2)

    new_root.left = mergeTrees(t1.left if t1 else None, t2.left if t2 else None)
    new_root.right = mergeTrees(t1.right if t1 else None, t2.right if t2 else None)

    return new_root

# 测试用例
def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []

# 构建测试树
t1 = TreeNode(1)
t1.left = TreeNode(3)
t1.left.left = TreeNode(5)
t1.right = TreeNode(2)

t2 = TreeNode(2)
t2.left = TreeNode(1)
t2.left.right = TreeNode(4)
t2.right = TreeNode(3)
t2.right.right = TreeNode(7)

# 合并树并输出中序遍历结果
merged_tree = mergeTrees(t1, t2)
print(inorder_traversal(merged_tree))  # [5, 4, 4, 3, 5, 7]

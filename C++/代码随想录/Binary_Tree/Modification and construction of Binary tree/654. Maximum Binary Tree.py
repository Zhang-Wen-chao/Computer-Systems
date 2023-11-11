class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def constructMaximumBinaryTree(nums):
    if not nums:
        return None

    max_val = max(nums)
    max_index = nums.index(max_val)

    root = TreeNode(max_val)
    root.left = constructMaximumBinaryTree(nums[:max_index])
    root.right = constructMaximumBinaryTree(nums[max_index + 1:])

    return root

# 测试用例
def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []

# 构建最大二叉树
nums = [3, 2, 1, 6, 0, 5]
max_tree = constructMaximumBinaryTree(nums)

# 输出中序遍历结果
print(inorder_traversal(max_tree))  # [3, 2, 1, 6, 5, 0]

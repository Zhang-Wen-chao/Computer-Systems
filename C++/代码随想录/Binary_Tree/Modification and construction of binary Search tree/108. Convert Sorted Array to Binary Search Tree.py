class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def sortedArrayToBST(nums):
    if not nums:
        return None

    mid = len(nums) // 2
    root = TreeNode(nums[mid])
    root.left = sortedArrayToBST(nums[:mid])
    root.right = sortedArrayToBST(nums[mid+1:])

    return root

# 测试用例
nums = [-10, -3, 0, 5, 9]
result = sortedArrayToBST(nums)

# 函数来打印树的中序遍历结果
def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []

print(inorder_traversal(result))  # [-10, -3, 0, 5, 9]

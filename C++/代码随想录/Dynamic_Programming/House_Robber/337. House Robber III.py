class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def rob(root):
    def helper(node):
        if not node:
            return (0, 0)

        left = helper(node.left)
        right = helper(node.right)

        # 抢劫当前节点
        rob_current = node.val + left[1] + right[1]

        # 不抢劫当前节点
        not_rob_current = max(left) + max(right)

        return (rob_current, not_rob_current)

    return max(helper(root))

# 测试用例
root = TreeNode(3, TreeNode(2, None, TreeNode(3)), TreeNode(3, None, TreeNode(1)))
print(rob(root))  # 输出应该是 7

root = TreeNode(3, TreeNode(4, TreeNode(1), TreeNode(3)), TreeNode(5, None, TreeNode(1)))
print(rob(root))  # 输出应该是 9

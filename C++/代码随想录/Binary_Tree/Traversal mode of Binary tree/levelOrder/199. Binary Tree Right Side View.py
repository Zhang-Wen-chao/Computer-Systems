class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def rightSideView(root):
    if not root:
        return []

    right_view = []
    queue = [root]
    while queue:
        level_length = len(queue)
        for i in range(level_length):
            node = queue.pop(0)
            if i == level_length - 1:
                right_view.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

    return right_view

# 测试用例
root = TreeNode(1, TreeNode(2, None, TreeNode(5)), TreeNode(3, None, TreeNode(4)))
print(rightSideView(root))  # 输出应为 [1, 3, 4]

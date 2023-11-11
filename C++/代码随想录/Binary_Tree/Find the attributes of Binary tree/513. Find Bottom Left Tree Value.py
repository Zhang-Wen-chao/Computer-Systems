class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def findBottomLeftValue(root):
    queue = [root]
    while queue:
        node = queue.pop(0)
        if node.right:
            queue.append(node.right)
        if node.left:
            queue.append(node.left)
    return node.val

# 测试用例
tree1 = TreeNode(2)
tree1.left = TreeNode(1)
tree1.right = TreeNode(3)

print(findBottomLeftValue(tree1))  # 1

tree2 = TreeNode(1)
tree2.left = TreeNode(2)
tree2.right = TreeNode(3)
tree2.left.left = TreeNode(4)
tree2.right.left = TreeNode(5)
tree2.right.right = TreeNode(6)
tree2.right.left.left = TreeNode(7)

print(findBottomLeftValue(tree2))  # 7

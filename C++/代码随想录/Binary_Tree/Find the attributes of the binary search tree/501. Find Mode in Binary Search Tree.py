class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def findMode(root):
    if not root:
        return []

    def inorder(node):
        if node:
            inorder(node.left)
            if node.val == inorder.prev_val:
                inorder.count += 1
            else:
                inorder.prev_val = node.val
                inorder.count = 1

            if inorder.count > inorder.max_count:
                inorder.max_count = inorder.count
                inorder.modes = [node.val]
            elif inorder.count == inorder.max_count:
                inorder.modes.append(node.val)

            inorder(node.right)

    inorder.prev_val = None
    inorder.count = 0
    inorder.max_count = 0
    inorder.modes = []
    inorder(root)
    return inorder.modes

# 测试用例
root = TreeNode(1)
root.right = TreeNode(2)
root.right.left = TreeNode(2)

print(findMode(root))  # [2]

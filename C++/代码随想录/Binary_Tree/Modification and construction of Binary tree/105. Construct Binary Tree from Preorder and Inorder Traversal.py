class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def buildTree(preorder, inorder):
    if not preorder or not inorder:
        return None

    # 前序遍历的第一个值是根节点
    root = TreeNode(preorder[0])
    mid = inorder.index(preorder[0])

    # 递归构建左右子树
    root.left = buildTree(preorder[1:mid+1], inorder[:mid])
    root.right = buildTree(preorder[mid+1:], inorder[mid+1:])

    return root

# 测试用例
def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
tree = buildTree(preorder, inorder)
print(inorder_traversal(tree))  # [9, 3, 15, 20, 7]

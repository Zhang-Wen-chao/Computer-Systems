class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def buildTree(inorder, postorder):
    if not inorder or not postorder:
        return None

    # 后序遍历的最后一个值是根节点
    root = TreeNode(postorder[-1])
    mid = inorder.index(postorder[-1])

    # 递归构建左右子树
    root.left = buildTree(inorder[:mid], postorder[:mid])
    root.right = buildTree(inorder[mid+1:], postorder[mid:-1])

    return root

# 测试用例
def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
tree = buildTree(inorder, postorder)
print(inorder_traversal(tree))  # [9, 3, 15, 20, 7]

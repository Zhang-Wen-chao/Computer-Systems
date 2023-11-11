class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def postorderTraversal(root):
    if not root:
        return []
    
    result = []
    result.extend(postorderTraversal(root.left))
    result.extend(postorderTraversal(root.right))
    result.append(root.val)
    return result

# 测试用例
root = TreeNode(1, None, TreeNode(2, TreeNode(3)))
print(postorderTraversal(root))  # 应输出 [3, 2, 1]

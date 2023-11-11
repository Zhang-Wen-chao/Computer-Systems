class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def preorderTraversal(root):
    if not root:
        return []
    
    result = [root.val]
    result.extend(preorderTraversal(root.left))
    result.extend(preorderTraversal(root.right))
    return result

# 测试用例
root = TreeNode(1, None, TreeNode(2, TreeNode(3)))
print(preorderTraversal(root))  # 应输出 [1, 2, 3]

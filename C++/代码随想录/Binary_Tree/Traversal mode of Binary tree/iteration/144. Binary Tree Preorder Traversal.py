class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def inorderTraversal(root):
    if not root:
        return []
    
    result = []
    result.append(root.val)
    result.extend(inorderTraversal(root.left))
    result.extend(inorderTraversal(root.right))
    return result

# 测试用例
root = TreeNode(1, None, TreeNode(2, TreeNode(3)))
print(inorderTraversal(root)) 

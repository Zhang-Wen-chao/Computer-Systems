class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isSubtree(s, t):
    if not s:
        return False
    if isSameTree(s, t):
        return True
    return isSubtree(s.left, t) or isSubtree(s.right, t)

def isSameTree(s, t):
    if not s and not t:
        return True
    if s and t and s.val == t.val:
        return isSameTree(s.left, t.left) and isSameTree(s.right, t.right)
    return False

# 测试用例
s = TreeNode(3)
s.left = TreeNode(4)
s.right = TreeNode(5)
s.left.left = TreeNode(1)
s.left.right = TreeNode(2)

t = TreeNode(4)
t.left = TreeNode(1)
t.right = TreeNode(2)

print(isSubtree(s, t))  # True

# 另一个测试用例
s2 = TreeNode(3)
s2.left = TreeNode(4)
s2.right = TreeNode(5)
s2.left.left = TreeNode(1)
s2.left.right = TreeNode(2)
s2.left.right.left = TreeNode(0)

t2 = TreeNode(4)
t2.left = TreeNode(1)
t2.right = TreeNode(2)

print(isSubtree(s2, t2))  # False

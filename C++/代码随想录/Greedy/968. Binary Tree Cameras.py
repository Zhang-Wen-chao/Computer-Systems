class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def minCameraCover(root):
    def dfs(node):
        if not node:
            return 0, 0, float('inf')
        L = dfs(node.left)
        R = dfs(node.right)
        dp0 = L[1] + R[1]
        dp1 = min(L[2] + min(R[1], R[2]), R[2] + min(L[1], L[2]))
        dp2 = 1 + min(L) + min(R)
        return dp0, dp1, dp2

    return min(dfs(root)[1:])

# 测试用例
root = TreeNode(0, TreeNode(0, TreeNode(0), TreeNode(0)), None)
print(minCameraCover(root))  # 应该输出 1

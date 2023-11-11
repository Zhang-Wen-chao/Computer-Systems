class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def binaryTreePaths(root):
    if not root:
        return []
    paths = []
    dfs(root, "", paths)
    return paths

def dfs(node, path, paths):
    if not node.left and not node.right:
        paths.append(path + str(node.val))
    if node.left:
        dfs(node.left, path + str(node.val) + "->", paths)
    if node.right:
        dfs(node.right, path + str(node.val) + "->", paths)

# 测试用例
tree1 = TreeNode(1)
tree1.left = TreeNode(2)
tree1.right = TreeNode(3)
tree1.left.right = TreeNode(5)

print(binaryTreePaths(tree1))  # ["1->2->5", "1->3"]

tree2 = TreeNode(1)
tree2.left = TreeNode(2)

print(binaryTreePaths(tree2))  # ["1->2"]

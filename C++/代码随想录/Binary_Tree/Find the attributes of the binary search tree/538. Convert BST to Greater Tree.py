from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def traverse(node, acc_sum):
            if node:
                acc_sum = traverse(node.right, acc_sum)
                node.val += acc_sum
                acc_sum = node.val
                acc_sum = traverse(node.left, acc_sum)
            return acc_sum

        traverse(root, 0)
        return root

# Test case
root = TreeNode(4, TreeNode(1, TreeNode(0), TreeNode(2, None, TreeNode(3))), TreeNode(6, TreeNode(5), TreeNode(7, None, TreeNode(8))))
sol = Solution()
converted_tree = sol.convertBST(root)
# 这将转换二叉搜索树，并更新每个节点的值

# 打印用例
def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []
print(inorder_traversal(converted_tree)) 
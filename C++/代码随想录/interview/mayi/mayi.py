class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def bstToDoublyList(self, root):
        if not root:
            return None

        self.prev = None
        head = None

        def inorder(node):
            nonlocal head
            if not node:
                return
            inorder(node.left)
            if self.prev:
                node.left = self.prev
                self.prev.right = node
            else:
                head = node
            self.prev = node
            inorder(node.right)

        inorder(root)
        return head

# 测试用例
# 构建 BST
#              10
#         6          12
#      4     8   11      16
root = TreeNode(10)
root.left = TreeNode(6)
root.right = TreeNode(12)
root.left.left = TreeNode(4)
root.left.right = TreeNode(8)
root.right.left = TreeNode(11)
root.right.right = TreeNode(16)

# 转换为双向链表并打印结果
solution = Solution()
head = solution.bstToDoublyList(root)
current = head
while current:
    print(current.val, end=" <-> " if current.right else "\n")
    current = current.right

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isMirror(left, right):
    # If both subtrees are None, then they are mirrors of each other
    if not left and not right:
        return True
    # If only one of the subtrees is None, then they are not mirrors
    if not left or not right:
        return False
    # Two trees are a mirror reflection of each other if:
    # 1. Their two roots have the same value
    # 2. The right subtree of each tree is a mirror reflection of the left subtree of the other tree
    return (left.val == right.val) and isMirror(left.right, right.left) and isMirror(left.left, right.right)

def isSymmetric(root):
    return isMirror(root, root)

# Helper function to create a binary tree from a list of values
def create_binary_tree(lst, index=0):
    if index >= len(lst) or lst[index] is None:
        return None
    root = TreeNode(lst[index])
    root.left = create_binary_tree(lst, 2 * index + 1)
    root.right = create_binary_tree(lst, 2 * index + 2)
    return root

# Test cases
tree1 = create_binary_tree([1, 2, 2, 3, 4, 4, 3])
print(isSymmetric(tree1))  # Output: True

tree2 = create_binary_tree([1, 2, 2, None, 3, None, 3])
print(isSymmetric(tree2))  # Output: False

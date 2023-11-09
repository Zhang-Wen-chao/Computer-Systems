class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isSameTree(p, q):
    # If both nodes are None, they are the same
    if not p and not q:
        return True
    # If one of the nodes is None, trees are not the same
    if not p or not q:
        return False
    # If the values of the nodes are different, trees are not the same
    if p.val != q.val:
        return False
    # Recursively check the left and right subtrees
    return isSameTree(p.left, q.left) and isSameTree(p.right, q.right)

# Helper function to create a binary tree from a list of values
def create_binary_tree(lst, index=0):
    if index >= len(lst) or lst[index] is None:
        return None
    root = TreeNode(lst[index])
    root.left = create_binary_tree(lst, 2 * index + 1)
    root.right = create_binary_tree(lst, 2 * index + 2)
    return root

# Test cases
tree1 = create_binary_tree([1, 2, 3])
tree2 = create_binary_tree([1, 2, 3])
print(isSameTree(tree1, tree2))  # Output: True

tree1 = create_binary_tree([1, 2])
tree2 = create_binary_tree([1, None, 2])
print(isSameTree(tree1, tree2))  # Output: False

tree1 = create_binary_tree([1, 2, 1])
tree2 = create_binary_tree([1, 1, 2])
print(isSameTree(tree1, tree2))  # Output: False

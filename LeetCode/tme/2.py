from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_tree(level_order):
    if not level_order or level_order[0] == '#':
        return None
    
    root = TreeNode(level_order[0])
    queue = deque([root])
    i = 1
    
    while i < len(level_order):
        current = queue.popleft()
        
        if i < len(level_order) and level_order[i] != '#':
            current.left = TreeNode(level_order[i])
            queue.append(current.left)
        i += 1
        
        if i < len(level_order) and level_order[i] != '#':
            current.right = TreeNode(level_order[i])
            queue.append(current.right)
        i += 1
    
    return root

def find_last_node(root):
    if not root:
        return None
    
    queue = deque([root])
    last_node = None
    
    while queue:
        last_node = queue.popleft()
        
        if last_node.left:
            queue.append(last_node.left)
        if last_node.right:
            queue.append(last_node.right)
    
    return last_node

def tree_to_level_order(root):
    if not root:
        return "{}"
    
    result = []
    queue = deque([root])
    
    while queue:
        node = queue.popleft()
        if node:
            result.append(node.val)
            queue.append(node.left)
            queue.append(node.right)
        else:
            result.append('#')
    
    # Remove trailing '#' symbols for a cleaner output
    while result and result[-1] == '#':
        result.pop()
    
    return "{" + "," + ",".join(map(str, result)) + "}"

def build_complete_tree_from_last_node(root):
    if not root:
        return None
    
    last_node = find_last_node(root)
    
    # Return the complete binary tree up to the last node
    return root

# Example usage
level_order = [1, '#', 1, 1]  # Example input
root = build_tree(level_order)
complete_tree = build_complete_tree_from_last_node(root)
output = tree_to_level_order(complete_tree)
print(output)

class Node:
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

def connect(root):
    if not root:
        return None

    leftmost = root
    while leftmost.left:
        head = leftmost
        while head:
            head.left.next = head.right
            if head.next:
                head.right.next = head.next.left
            head = head.next
        leftmost = leftmost.left

    return root


def print_tree_with_next_pointer(root):
    level = [root]
    while level:
        next_level = []
        for node in level:
            next_val = node.next.val if node.next else None
            print(f"Node {node.val} -> Next Node {next_val}")
            if node.left:
                next_level.append(node.left)
            if node.right:
                next_level.append(node.right)
        level = next_level

# 测试用例
root = Node(1, Node(2, Node(4), Node(5)), Node(3, Node(6), Node(7)))
connect(root)
print_tree_with_next_pointer(root)
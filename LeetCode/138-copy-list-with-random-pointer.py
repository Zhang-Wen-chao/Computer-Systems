# -*- coding: utf-8 -*-

class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

def copyRandomList(head: 'Optional[Node]') -> 'Optional[Node]':
    if not head:
        return None
    
    # Step 1: Copy each node and insert the copy right after the original node
    current = head
    while current:
        new_node = Node(current.val)
        new_node.next = current.next
        current.next = new_node
        current = new_node.next
    
    # Step 2: Assign random pointers for the copied nodes
    current = head
    while current:
        if current.random:
            current.next.random = current.random.next
        current = current.next.next
    
    # Step 3: Separate the copied nodes to form the new list
    current = head
    copy_head = head.next
    copy_current = copy_head
    
    while current:
        current.next = current.next.next
        if copy_current.next:
            copy_current.next = copy_current.next.next
        current = current.next
        copy_current = copy_current.next
    
    return copy_head

# 辅助函数：打印链表
def print_list(head, node_names):
    current = head
    nodes = []
    random_pointers = []
    while current:
        nodes.append(current)
        if current.random:
            random_pointers.append((current, current.random))
        current = current.next

    # 打印节点和 next 指针
    for i, node in enumerate(nodes):
        print(f'{node_names[i]}({node.val})', end='')
        if node.next:
            print(' -> ', end='')
    print()

    # 打印 random 指针
    for start, end in random_pointers:
        start_index = nodes.index(start)
        end_index = nodes.index(end)
        if start_index < end_index:
            print(' ' * (start_index * 6 + 2) + '└' + '─' * (6 * (end_index - start_index) - 3) + '→ ' + node_names[end_index])
        else:
            print(' ' * (end_index * 6 + 2) + '↑')
            print(' ' * (end_index * 6 + 2) + '│' + ' ' * (6 * (start_index - end_index) - 3) + ' ' + node_names[start_index])
            print(' ' * (end_index * 6 + 2) + '└' + '─' * (6 * (start_index - end_index) - 3) + '←')

# 测试代码
a = Node(1)
b = Node(2)
c = Node(3)
d = Node(4)
e = Node(5)
f = Node(6)

a.next = b
b.next = c
c.next = d
d.next = e
e.next = f

a.random = c
b.random = a
d.random = a

node_names = ['a', 'b', 'c', 'd', 'e', 'f']

# 打印原始链表
print("Original list:")
print_list(a, node_names)

# 复制链表
new_head = copyRandomList(a)

# 打印复制后的链表
print("\nCopied list:")
print_list(new_head, node_names)

class ListNode:
    def __init__(self, value=0, next=None):
        self.val = value
        self.next = next

def swapPairs(head):
    dummy = ListNode(0)
    dummy.next = head
    current = dummy
    
    while current.next and current.next.next:
        first = current.next
        second = current.next.next
        
        # Swapping the nodes
        first.next = second.next
        second.next = first
        current.next = second
        
        # Move to the next pair
        current = first
    
    return dummy.next

# Helper function to create a linked list from a list of values
def create_linked_list(lst):
    dummy = ListNode(0)
    current = dummy
    for value in lst:
        current.next = ListNode(value)
        current = current.next
    return dummy.next

# Helper function to convert a linked list to a list of values
def linked_list_to_list(node):
    result = []
    while node:
        result.append(node.val)
        node = node.next
    return result

# Test cases
head = create_linked_list([1, 2, 3, 4])
new_head = swapPairs(head)
print(linked_list_to_list(new_head))  # Output: [2, 1, 4, 3]

head = create_linked_list([1])
new_head = swapPairs(head)
print(linked_list_to_list(new_head))  # Output: [1]

head = create_linked_list([])
new_head = swapPairs(head)
print(linked_list_to_list(new_head))  # Output: []

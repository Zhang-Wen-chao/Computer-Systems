class ListNode:
    def __init__(self, value=0, next=None):
        self.val = value
        self.next = next

def removeNthFromEnd(head, n):
    dummy = ListNode(0)
    dummy.next = head
    first = dummy
    second = dummy
    
    # Advance first pointer so that the gap between first and second is n nodes apart
    for i in range(n + 1):
        first = first.next
    
    # Move first to the end, maintaining the gap
    while first is not None:
        first = first.next
        second = second.next
    
    # Skip the desired node
    second.next = second.next.next
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
head = create_linked_list([1, 2, 3, 4, 5])
n = 2
new_head = removeNthFromEnd(head, n)
print(linked_list_to_list(new_head))  # Output: [1, 2, 3, 5]

head = create_linked_list([1])
n = 1
new_head = removeNthFromEnd(head, n)
print(linked_list_to_list(new_head))  # Output: []

head = create_linked_list([1, 2])
n = 1
new_head = removeNthFromEnd(head, n)
print(linked_list_to_list(new_head))  # Output: [1]

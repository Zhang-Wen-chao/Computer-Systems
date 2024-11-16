# 给出一个长度为n的链表，a1,a2,.......an代表对于第 i 个链表单元、存放一个数值ai。
# 我们称这个链表是优美的,当且仅当这个链表满足以下条件:
# 1.若a_i=0,如a_i-1存在,则a_i-1不等于0;
# 2.若a_i≠0,如a_i-1存在,则a_i-1 = 0;

# 对于一个节点和相邻节点,我们可以将其合并成一个节点,该节点权值为原来两个节点的权值较大值。

# 我们想通过最少次数的合并来形成一个优美链表,输出该次数。
# 补充说明
# 函数的第一个参数输入一个长度为n(1<n<10^5)的ListNode类 a1,a2,.....an(0<a_i<10^9)代表链表a 。



# 我觉得这个代码没问题，但是一个都没过。
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def min_merge_to_beautiful(head):
    if not head or not head.next:
        return 0

    current = head
    merge_count = 0

    while current and current.next:
        # if current.val == 0 and current.next.val == 0:
        if (current.val == 0 and current.next.val == 0) or (current.val != 0 and current.next.val != 0):
            # 如果连续的两个节点都是0，则合并它们
            current.val = max(current.val, current.next.val)
            current.next = current.next.next
            merge_count += 1
        else:
            # 否则，链表当前已经是优美的，继续向前遍历
            current = current.next

    return merge_count

# 测试函数
def create_linked_list(arr):
    if not arr:
        return None

    head = ListNode(arr[0])
    current = head

    for num in arr[1:]:
        current.next = ListNode(num)
        current = current.next

    return head

# 测试用例
head1 = create_linked_list([0, 1, 0])
output1 = min_merge_to_beautiful(head1)
print(output1)  # 预期输出: 0

head2 = create_linked_list([0, 0, 1, 2])
output2 = min_merge_to_beautiful(head2)
print(output2)  # 预期输出: 2

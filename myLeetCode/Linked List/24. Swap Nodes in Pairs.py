# 24. Swap Nodes in Pairs
# https://leetcode.com/problems/swap-nodes-in-pairs/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummyHead = ListNode(0)
        dummyHead.next = head
        temp = dummyHead
        while temp.next and temp.next.next:
            node1 = temp.next
            node2 = temp.next.next
            temp.next = node2
            node1.next = node2.next
            node2.next = node1
            temp = node1
        newHead = dummyHead.next
        del dummyHead  # 释放dummyHead内存
        return newHead

def main():
    values = [1, 2, 3, 4, 5, 6]
    head = None
    curr = None
    for val in values:
        if head is None:
            head = ListNode(val)
            curr = head
        else:
            curr.next = ListNode(val)
            curr = curr.next

    # 调用函数进行节点交换
    sol = Solution()
    swapped = sol.swapPairs(head)

    # 输出结果
    while swapped:
        print(swapped.val, end=" ")
        swapped = swapped.next
    print()

if __name__ == "__main__":
    main()
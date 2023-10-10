// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
using System;

public class ListNode {
    public int val;
    public ListNode next;
    public ListNode(int x) { val = x; }
}

public class Solution {
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode first = dummy;
        ListNode second = dummy;

        for (int i = 1; i <= n + 1; i++) {
            first = first.next;
        }

        while (first != null) {
            first = first.next;
            second = second.next;
        }
        second.next = second.next.next;

        return dummy.next;
    }
}

public class Program {
    public static void Main() {
        int[] nums = {1, 2, 3, 4, 5};
        ListNode head = ListHelpers.ConvertArrayToList(nums);

        Solution solution = new Solution();
        ListNode result = solution.RemoveNthFromEnd(head, 2);

        Console.Write("Output: ");
        while (result != null) {
            Console.Write(result.val + " ");
            result = result.next;
        }
    }
}

using System;

public class Solution {
    public ListNode SwapPairs(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode current = dummy;

        while (current.next != null && current.next.next != null) {
            ListNode firstNode = current.next;
            ListNode secondNode = current.next.next;

            firstNode.next = secondNode.next;
            current.next = secondNode;
            current.next.next = firstNode;
            current = current.next.next;
        }

        return dummy.next;
    }
}

public class Program {
    public static void Main() {
        int[] nums = {1, 2, 3, 4};
        ListNode head = ListHelpers.ConvertArrayToList(nums);

        Solution solution = new Solution();
        ListNode result = solution.SwapPairs(head);

        Console.Write("Output: ");
        while (result != null) {
            Console.Write(result.val + " ");
            result = result.next;
        }
    }
}

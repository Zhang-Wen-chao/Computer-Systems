// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/

using System;

public class Solution {
    public ListNode RemoveElements(ListNode head, int val) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode current = dummy;
        while (current.next != null) {
            if (current.next.val == val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
        return dummy.next;
    }
}

public class Program {
    public static void Main() {
        int[] nums = {1, 2, 6, 3, 4, 5, 6};
        ListNode head = ListHelpers.ConvertArrayToList(nums);

        Solution solution = new Solution();
        ListNode result = solution.RemoveElements(head, 6);

        Console.Write("Output: ");
        while (result != null) {
            Console.Write(result.val + " ");
            result = result.next;
        }
    }
}



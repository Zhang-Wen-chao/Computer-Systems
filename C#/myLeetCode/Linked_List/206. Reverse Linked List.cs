// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

using System;

public class Solution {
    public ListNode ReverseList(ListNode head) {
        ListNode prev = null;
        ListNode current = head;

        while (current != null) {
            ListNode nextTemp = current.next;
            current.next = prev;
            prev = current;
            current = nextTemp;
        }
        
        return prev;
    }
}

public class Program {
    public static void Main() {
        int[] nums = {1, 2, 3, 4, 5};
        ListNode head = ListHelpers.ConvertArrayToList(nums);

        Solution solution = new Solution();
        ListNode result = solution.ReverseList(head);

        Console.Write("Output: ");
        while (result != null) {
            Console.Write(result.val + " ");
            result = result.next;
        }
    }
}

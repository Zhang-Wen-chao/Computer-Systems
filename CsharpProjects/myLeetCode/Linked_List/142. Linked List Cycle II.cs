// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/

using System;

public class Solution {
    public ListNode DetectCycle(ListNode head) {
        if (head == null || head.next == null) return null;

        ListNode slow = head, fast = head;

        // 使用 Floyd's Cycle Detection 算法
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) break; // cycle detected
        }

        // 检查是否没有循环
        if (fast == null || fast.next == null) return null;

        slow = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }

        return slow; // 这就是循环开始的节点
    }
}
public class Program {
    public static void Main() {
        // 使用 ListHelpers 创建链表
        int[] nums = {3, 2, 0, -4};
        ListNode head = ListHelpers.ConvertArrayToList(nums);

        // 手动创建循环
        if (head != null && head.next != null && head.next.next != null && head.next.next.next != null) {
            head.next.next.next.next = head.next;
        }

        Solution solution = new Solution();
        ListNode cycleStart = solution.DetectCycle(head);

        if (cycleStart != null) {
            Console.WriteLine($"Cycle detected! Cycle starts at node with value: {cycleStart.val}");
        } else {
            Console.WriteLine("No cycle detected in the linked list.");
        }
    }
}

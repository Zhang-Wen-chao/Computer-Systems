// 面试题 02.07. 链表相交
// https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
using System;

public class Solution {
    public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;

        ListNode a = headA, b = headB;

        while (a != b) {
            a = a != null ? a.next : headB;
            b = b != null ? b.next : headA;
        }

        return a;
    }
}

public class Program {
    public static void Main() {
        // Using ConvertArrayToList to create Sample Linked Lists
        int[] commonArray = {8, 4, 5};
        ListNode common = ListHelpers.ConvertArrayToList(commonArray);

        int[] listAArray = {4, 1};
        ListNode listA = ListHelpers.ConvertArrayToList(listAArray);
        ListNode currA = listA;
        while (currA.next != null) currA = currA.next;
        currA.next = common;

        int[] listBArray = {5, 0, 1};
        ListNode listB = ListHelpers.ConvertArrayToList(listBArray);
        ListNode currB = listB;
        while (currB.next != null) currB = currB.next;
        currB.next = common;

        Solution solution = new Solution();
        ListNode intersection = solution.GetIntersectionNode(listA, listB);

        if (intersection != null) {
            Console.WriteLine($"Intersection Node Value: {intersection.val}");
        } else {
            Console.WriteLine("No Intersection");
        }
    }
}

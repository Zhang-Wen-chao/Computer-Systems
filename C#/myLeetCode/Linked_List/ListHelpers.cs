using System;

public class ListNode {
    public int val;
    public ListNode next;
    public ListNode(int x) {
        val = x;
        next = null;
    }
}

public static class ListHelpers {
    public static ListNode ConvertArrayToList(int[] arr) {
        if (arr == null || arr.Length == 0) return null;

        ListNode dummy = new ListNode(0);
        ListNode current = dummy;

        foreach (int num in arr) {
            current.next = new ListNode(num);
            current = current.next;
        }

        return dummy.next;
    }

    // ... 其他辅助方法
}

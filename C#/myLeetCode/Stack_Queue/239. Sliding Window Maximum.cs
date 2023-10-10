// 239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/
using System.Collections.Generic;

public class Solution {
    public int[] MaxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.Length == 0) return new int[0];

        int[] result = new int[nums.Length - k + 1];
        LinkedList<int> deque = new LinkedList<int>();

        for (int i = 0; i < nums.Length; i++) {
            // 从deque的尾部移除小于滑动窗口左边界的索引
            if (deque.Count > 0 && deque.First.Value < i - k + 1) {
                deque.RemoveFirst();
            }

            // 从deque的尾部移除小于当前数字的所有索引
            while (deque.Count > 0 && nums[deque.Last.Value] < nums[i]) {
                deque.RemoveLast();
            }

            // 将当前元素添加到deque的尾部
            deque.AddLast(i);

            if (i >= k - 1) {
                result[i - k + 1] = nums[deque.First.Value];
            }
        }

        return result;
    }
}
public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] nums = new int[] {1,3,-1,-3,5,3,6,7};
        int k = 3;
        int[] result = solution.MaxSlidingWindow(nums, k);

        Console.WriteLine($"Input: {string.Join(", ", nums)}");
        Console.WriteLine($"Output: {string.Join(", ", result)}");
    }
}

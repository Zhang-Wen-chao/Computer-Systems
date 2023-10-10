// 704. Binary Search
// https://leetcode.com/problems/binary-search/

using System;

public class Solution {
    public int Search(int[] nums, int target) {
        int left = 0;
        int right = nums.Length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1; // target was not found in the array
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] nums = {-1, 0, 3, 5, 9, 12};
        int target = 9;

        int result = solution.Search(nums, target);

        if (result != -1) {
            Console.WriteLine($"Target {target} found at index: {result}");
        } else {
            Console.WriteLine($"Target {target} not found in the array.");
        }
    }
}

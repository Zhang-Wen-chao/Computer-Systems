// 977. Squares of a Sorted Array
// https://leetcode.com/problems/squares-of-a-sorted-array/

using System;

public class Solution {
    public int[] SortedSquares(int[] nums) {
        int n = nums.Length;
        int[] result = new int[n];
        int left = 0, right = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (Math.Abs(nums[left]) < Math.Abs(nums[right])) {
                result[i] = nums[right] * nums[right];
                right--;
            } else {
                result[i] = nums[left] * nums[left];
                left++;
            }
        }

        return result;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] nums = {-4, -1, 0, 3, 10};

        int[] result = solution.SortedSquares(nums);

        Console.WriteLine("Sorted Squares Array:");
        foreach (int val in result) {
            Console.Write(val + " ");
        }
    }
}


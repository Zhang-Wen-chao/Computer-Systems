// 27. Remove Element
// https://leetcode.com/problems/remove-element/
using System;
using System.Collections.Generic;

public class Solution {
    public int RemoveElement(List<int> nums, int val) {
        int n = nums.Count;
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
}

public class Program {
    public static void Main() {
        List<int> nums = new List<int> {0, 1, 2, 2, 3, 0, 4, 2};
        int target = 2;
        Solution solution = new Solution();
        int ans = solution.RemoveElement(nums, target);

        Console.WriteLine(ans);

        for (int i = 0; i < ans; i++) {
            Console.Write(nums[i] + " ");
        }
        Console.WriteLine();
    }
}

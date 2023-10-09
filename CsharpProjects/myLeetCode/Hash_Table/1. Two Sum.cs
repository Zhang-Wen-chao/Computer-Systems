// 1. Two Sum
// https://leetcode.cn/problems/two-sum/
using System;
using System.Collections.Generic;

public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> dict = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++) {
            int complement = target - nums[i];
            if (dict.ContainsKey(complement)) {
                return new int[] { dict[complement], i };
            }
            dict[nums[i]] = i;
        }
        throw new ArgumentException("No two sum solution");
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] nums = {2, 7, 11, 15};
        int target = 9;

        int[] result = solution.TwoSum(nums, target);

        Console.WriteLine($"Given nums = [{string.Join(", ", nums)}], target = {target}");
        Console.WriteLine($"Indices of the two numbers are: [{string.Join(", ", result)}]");
    }
}

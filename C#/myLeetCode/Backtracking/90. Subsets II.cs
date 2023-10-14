// LeetCode 90. Subsets II
// https://leetcode.com/problems/subsets-ii/

using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<int>> SubsetsWithDup(int[] nums) {
        Array.Sort(nums); // 先对数组进行排序，以处理重复元素
        IList<IList<int>> result = new List<IList<int>>();
        SubsetsHelper(nums, 0, new List<int>(), result);
        return result;
    }

    private void SubsetsHelper(int[] nums, int start, List<int> current, IList<IList<int>> result) {
        result.Add(new List<int>(current));

        for (int i = start; i < nums.Length; i++) {
            // 处理重复元素
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            current.Add(nums[i]);
            SubsetsHelper(nums, i + 1, current, result);
            current.RemoveAt(current.Count - 1);
        }
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] nums = { 1, 2, 2 };
        IList<IList<int>> result = solution.SubsetsWithDup(nums);

        Console.WriteLine("All subsets of the given array:");
        foreach (var subset in result) {
            Console.WriteLine(string.Join(" ", subset));
        }
    }
}

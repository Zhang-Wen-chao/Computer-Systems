// 78. Subsets
// https://leetcode.com/problems/subsets/

using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<int>> Subsets(int[] nums) {
        IList<IList<int>> result = new List<IList<int>>();
        SubsetsHelper(nums, 0, new List<int>(), result);
        return result;
    }

    private void SubsetsHelper(int[] nums, int start, List<int> current, IList<IList<int>> result) {
        result.Add(new List<int>(current));

        for (int i = start; i < nums.Length; i++) {
            current.Add(nums[i]);
            SubsetsHelper(nums, i + 1, current, result);
            current.RemoveAt(current.Count - 1);
        }
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] nums = { 1, 2, 3 };
        IList<IList<int>> result = solution.Subsets(nums);

        Console.WriteLine("All subsets of the given array:");
        foreach (var subset in result) {
            Console.WriteLine(string.Join(" ", subset));
        }
    }
}

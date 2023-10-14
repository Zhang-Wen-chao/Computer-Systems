// 46. Permutations
// https://leetcode.com/problems/permutations/

using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<int>> Permute(int[] nums) {
        IList<IList<int>> result = new List<IList<int>>();
        List<int> current = new List<int>();
        bool[] used = new bool[nums.Length];
        PermuteHelper(nums, used, current, result);
        return result;
    }

    private void PermuteHelper(int[] nums, bool[] used, List<int> current, IList<IList<int>> result) {
        if (current.Count == nums.Length) {
            result.Add(new List<int>(current));
            return;
        }

        for (int i = 0; i < nums.Length; i++) {
            if (!used[i]) {
                used[i] = true;
                current.Add(nums[i]);
                PermuteHelper(nums, used, current, result);
                current.RemoveAt(current.Count - 1);
                used[i] = false;
            }
        }
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] nums = { 1, 2, 3 };

        IList<IList<int>> result = solution.Permute(nums);

        Console.WriteLine("All permutations:");
        foreach (var permutation in result) {
            Console.WriteLine(string.Join(" ", permutation));
        }
    }
}

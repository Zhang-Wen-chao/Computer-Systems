// 47. Permutations II
// https://leetcode.com/problems/permutations-ii/

using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<int>> PermuteUnique(int[] nums) {
        IList<IList<int>> result = new List<IList<int>>();
        List<int> current = new List<int>();
        bool[] used = new bool[nums.Length];
        Array.Sort(nums);
        PermuteUniqueHelper(nums, used, current, result);
        return result;
    }

    private void PermuteUniqueHelper(int[] nums, bool[] used, List<int> current, IList<IList<int>> result) {
        if (current.Count == nums.Length) {
            result.Add(new List<int>(current));
            return;
        }

        for (int i = 0; i < nums.Length; i++) {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                continue;
            }
            used[i] = true;
            current.Add(nums[i]);
            PermuteUniqueHelper(nums, used, current, result);
            current.RemoveAt(current.Count - 1);
            used[i] = false;
        }
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] nums = { 1, 1, 2 };

        IList<IList<int>> result = solution.PermuteUnique(nums);

        Console.WriteLine("All unique permutations:");
        foreach (var permutation in result) {
            Console.WriteLine(string.Join(" ", permutation));
        }
    }
}

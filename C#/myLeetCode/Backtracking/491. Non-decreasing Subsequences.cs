// 491. Non-decreasing Subsequences
// https://leetcode.com/problems/non-decreasing-subsequences/

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public IList<IList<int>> FindSubsequences(int[] nums) {
        List<IList<int>> result = new List<IList<int>>();
        List<int> currentList = new List<int>();

        DFS(nums, 0, currentList, result);

        return result;
    }

    private void DFS(int[] nums, int index, List<int> currentList, List<IList<int>> result) {
        if (currentList.Count >= 2) {
            result.Add(new List<int>(currentList));
        }

        HashSet<int> used = new HashSet<int>();

        for (int i = index; i < nums.Length; i++) {
            if ((currentList.Count == 0 || nums[i] >= currentList.Last()) && !used.Contains(nums[i])) {
                currentList.Add(nums[i]);
                used.Add(nums[i]);
                DFS(nums, i + 1, currentList, result);
                currentList.RemoveAt(currentList.Count - 1);
            }
        }
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] nums = { 4, 6, 7, 7 };

        IList<IList<int>> result = solution.FindSubsequences(nums);

        // 打印结果
        foreach (var subsequence in result) {
            Console.WriteLine(string.Join(", ", subsequence));
        }
    }
}

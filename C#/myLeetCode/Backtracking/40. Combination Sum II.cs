// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/

using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<int>> CombinationSum2(int[] candidates, int target) {
        IList<IList<int>> result = new List<IList<int>>();
        Array.Sort(candidates); // 先对数组排序，以便后面剪枝
        List<int> current = new List<int>();
        FindCombinations(candidates, target, 0, current, result);
        return result;
    }

    private void FindCombinations(int[] candidates, int target, int start, List<int> current, IList<IList<int>> result) {
        if (target == 0) {
            result.Add(new List<int>(current));
            return;
        }

        for (int i = start; i < candidates.Length; i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                // 避免重复元素
                continue;
            }

            if (candidates[i] <= target) {
                current.Add(candidates[i]);
                FindCombinations(candidates, target - candidates[i], i + 1, current, result);
                current.RemoveAt(current.Count - 1);
            }
        }
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] candidates = { 10, 1, 2, 7, 6, 1, 5 };
        int target = 8;

        IList<IList<int>> result = solution.CombinationSum2(candidates, target);

        Console.WriteLine("Combinations that sum up to " + target + ":");
        foreach (var combination in result) {
            Console.WriteLine(string.Join(" ", combination));
        }
    }
}

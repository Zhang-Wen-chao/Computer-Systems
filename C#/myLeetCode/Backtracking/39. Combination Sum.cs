// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/

using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        IList<IList<int>> result = new List<IList<int>>();
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
            if (candidates[i] <= target) {
                current.Add(candidates[i]);
                FindCombinations(candidates, target - candidates[i], i, current, result);
                current.RemoveAt(current.Count - 1);
            }
        }
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] candidates = { 2, 3, 6, 7 };
        int target = 7;

        IList<IList<int>> result = solution.CombinationSum(candidates, target);

        Console.WriteLine("Combinations that sum up to " + target + ":");
        foreach (var combination in result) {
            Console.WriteLine(string.Join(" ", combination));
        }
    }
}

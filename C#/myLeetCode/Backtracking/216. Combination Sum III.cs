// 216. Combination Sum III
// https://leetcode.com/problems/combination-sum-iii/

using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<int>> CombinationSum3(int k, int n) {
        IList<IList<int>> result = new List<IList<int>>();
        List<int> currentCombination = new List<int>();
        GenerateCombinations(k, n, 1, currentCombination, result);
        return result;
    }

    private void GenerateCombinations(int k, int n, int start, List<int> currentCombination, IList<IList<int>> result) {
        if (k == 0 && n == 0) {
            result.Add(new List<int>(currentCombination));
            return;
        }

        if (k == 0 || n < 0) {
            return;
        }

        for (int i = start; i <= 9; i++) {
            currentCombination.Add(i);
            GenerateCombinations(k - 1, n - i, i + 1, currentCombination, result);
            currentCombination.RemoveAt(currentCombination.Count - 1);
        }
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int k = 3;
        int n = 7;

        IList<IList<int>> result = solution.CombinationSum3(k, n);

        // 打印结果
        foreach (var combination in result) {
            Console.WriteLine(string.Join(" ", combination));
        }
    }
}

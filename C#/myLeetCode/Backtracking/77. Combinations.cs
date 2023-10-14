// 77. Combinations
// https://leetcode.com/problems/combinations/

using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<int>> Combine(int n, int k) {
        IList<IList<int>> result = new List<IList<int>>();
        CombineHelper(n, k, 1, new List<int>(), result);
        return result;
    }

    private void CombineHelper(int n, int k, int start, List<int> current, IList<IList<int>> result) {
        if (current.Count == k) {
            result.Add(new List<int>(current));
            return;
        }

        for (int i = start; i <= n; i++) {
            current.Add(i);
            CombineHelper(n, k, i + 1, current, result);
            current.RemoveAt(current.Count - 1);
        }
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int n = 4;
        int k = 2;
        IList<IList<int>> result = solution.Combine(n, k);

        Console.WriteLine($"All combinations of {k} numbers from 1 to {n}:");
        foreach (var combination in result) {
            Console.WriteLine(string.Join(" ", combination));
        }
    }
}

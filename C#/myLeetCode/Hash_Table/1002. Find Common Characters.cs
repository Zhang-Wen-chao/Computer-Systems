// 1002. Find Common Characters
// https://leetcode.com/problems/find-common-characters/

using System;
using System.Collections.Generic;

public class Solution {
    public IList<string> CommonChars(string[] A) {
        int[][] charCounts = new int[A.Length][];
        for (int i = 0; i < A.Length; i++) {
            charCounts[i] = new int[26];
            foreach (char c in A[i]) {
                charCounts[i][c - 'a']++;
            }
        }

        List<string> result = new List<string>();
        for (int i = 0; i < 26; i++) {
            int minCount = int.MaxValue;
            for (int j = 0; j < A.Length; j++) {
                minCount = Math.Min(minCount, charCounts[j][i]);
            }

            for (int k = 0; k < minCount; k++) {
                result.Add(((char)('a' + i)).ToString());
            }
        }

        // 打印结果
        Console.WriteLine("Common characters:");
        foreach (string s in result) {
            Console.WriteLine(s);
        }

        return result;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();
        string[] words = {"bella", "label", "roller"};
        solution.CommonChars(words);
    }
}

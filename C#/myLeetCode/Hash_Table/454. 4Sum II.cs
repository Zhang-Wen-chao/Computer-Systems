// 454. 4Sum II
// https://leetcode.com/problems/4sum-ii/

using System;
using System.Collections.Generic;

public class Solution {
    public int FourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Dictionary<int, int> sumAB = new Dictionary<int, int>();
        int count = 0;

        // 计算A和B中所有可能的和，并存储在哈希表中
        foreach (int a in A) {
            foreach (int b in B) {
                int sum = a + b;
                if (sumAB.ContainsKey(sum)) {
                    sumAB[sum]++;
                } else {
                    sumAB[sum] = 1;
                }
            }
        }

        // 计算C和D中所有可能的和的负值，并检查它们在哈希表中出现的次数
        foreach (int c in C) {
            foreach (int d in D) {
                int sum = -(c + d);
                if (sumAB.ContainsKey(sum)) {
                    count += sumAB[sum];
                }
            }
        }

        // 打印结果
        Console.WriteLine($"Total ways to get sum 0: {count}");
        return count;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();
        int[] A = {1, 2};
        int[] B = {-2, -1};
        int[] C = {-1, 2};
        int[] D = {0, 2};
        solution.FourSumCount(A, B, C, D);
    }
}

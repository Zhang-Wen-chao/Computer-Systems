// 383. Ransom Note
// https://leetcode.com/problems/ransom-note/

using System;
using System.Collections.Generic;

public class Solution {
    public int[] Intersection(int[] nums1, int[] nums2) {
        HashSet<int> set1 = new HashSet<int>(nums1);
        HashSet<int> resultSet = new HashSet<int>();

        foreach (int num in nums2) {
            if (set1.Contains(num)) {
                resultSet.Add(num);
            }
        }

        // 打印交集的结果
        Console.WriteLine("Intersection:");
        foreach (int num in resultSet) {
            Console.WriteLine(num);
        }

        return resultSet.ToArray();
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();
        int[] nums1 = {1, 2, 2, 1};
        int[] nums2 = {2, 2};
        solution.Intersection(nums1, nums2);
    }
}

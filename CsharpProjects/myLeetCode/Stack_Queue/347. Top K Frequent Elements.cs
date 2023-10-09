// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public IList<int> TopKFrequent(int[] nums, int k) {
        // 使用字典来存储每个数字的频率
        Dictionary<int, int> frequency = new Dictionary<int, int>();

        foreach (int num in nums) {
            if (frequency.ContainsKey(num)) {
                frequency[num]++;
            } else {
                frequency[num] = 1;
            }
        }

        // 根据频率对字典进行排序，并取出前k个元素
        return frequency.OrderByDescending(p => p.Value).Take(k).Select(p => p.Key).ToList();
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] nums = new int[] {1,1,1,2,2,3};
        int k = 2;
        IList<int> result = solution.TopKFrequent(nums, k);

        Console.WriteLine($"Input: {string.Join(", ", nums)}");
        Console.WriteLine($"Top {k} frequent elements: {string.Join(", ", result)}");
    }
}

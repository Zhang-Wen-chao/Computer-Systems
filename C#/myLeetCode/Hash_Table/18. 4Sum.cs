// 18. 4Sum
// https://leetcode.com/problems/4sum/

using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<int>> FourSum(int[] nums, int target) {
        IList<IList<int>> result = new List<IList<int>>();
        if (nums == null || nums.Length < 4) return result;

        Array.Sort(nums);

        for (int i = 0; i < nums.Length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.Length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int low = j + 1;
                int high = nums.Length - 1;
                int sum = target - nums[i] - nums[j];

                while (low < high) {
                    if (nums[low] + nums[high] == sum) {
                        result.Add(new List<int> { nums[i], nums[j], nums[low], nums[high] });
                        while (low < high && nums[low] == nums[low + 1]) low++;
                        while (low < high && nums[high] == nums[high - 1]) high--;
                        low++;
                        high--;
                    } else if (nums[low] + nums[high] < sum) {
                        low++;
                    } else {
                        high--;
                    }
                }
            }
        }

        return result;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] nums = {1, 0, -1, 0, -2, 2};
        int target = 0;

        var results = solution.FourSum(nums, target);

        Console.WriteLine("4Sum combinations:");
        foreach (var combo in results) {
            Console.WriteLine($"[{string.Join(", ", combo)}]");
        }
    }
}

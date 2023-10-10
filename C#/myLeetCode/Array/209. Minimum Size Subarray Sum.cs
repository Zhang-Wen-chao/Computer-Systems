// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/

using System;

public class Solution {
    public int MinSubArrayLen(int target, int[] nums) {
        int minLength = int.MaxValue;
        int left = 0;
        int currentSum = 0;

        for (int right = 0; right < nums.Length; right++) {
            currentSum += nums[right];

            while (currentSum >= target) {
                minLength = Math.Min(minLength, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }

        return minLength == int.MaxValue ? 0 : minLength;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();
        
        int[] nums = {2,3,1,2,4,3};
        int target = 7;

        int result = solution.MinSubArrayLen(target, nums);
        Console.WriteLine("The minimum length of the subarray with a sum greater than or equal to " + target + " is: " + result);
    }
}

// 202. Happy Number
// https://leetcode.com/problems/happy-number/

using System;
using System.Collections.Generic;

public class Solution {
    public bool IsHappy(int n) {
        HashSet<int> seen = new HashSet<int>();
        
        while (n != 1 && !seen.Contains(n)) {
            Console.WriteLine(n);  // 打印当前的数字
            seen.Add(n);
            n = GetNext(n);
        }
        
        Console.WriteLine(n);  // 打印最后的数字
        return n == 1;
    }
    
    private int GetNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();
        int number = 19;
        Console.WriteLine($"Is {number} a happy number? {solution.IsHappy(number)}");
    }
}

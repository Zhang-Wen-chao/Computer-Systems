// 剑指 Offer 58 - II. 左旋转字符串
// https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/

public class Solution {
    public string ReverseLeftWords(string s, int n) {
        return s.Substring(n) + s.Substring(0, n);
    }
}
public class Program {
    public static void Main() {
        Solution solution = new Solution();

        string input = "abcdefg";
        int n = 2;
        string result = solution.ReverseLeftWords(input, n);

        Console.WriteLine($"Input: '{input}' with n={n}");
        Console.WriteLine($"Output: '{result}'");
    }
}

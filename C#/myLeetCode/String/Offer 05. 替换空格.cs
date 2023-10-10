// 剑指 Offer 05. 替换空格
// https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
public class Solution {
    public string ReplaceSpace(string s) {
        return s.Replace(" ", "%20");
    }
}
public class Program {
    public static void Main() {
        Solution solution = new Solution();

        string input = "We are happy.";
        string result = solution.ReplaceSpace(input);

        Console.WriteLine($"Input: '{input}'");
        Console.WriteLine($"Output: '{result}'");
    }
}

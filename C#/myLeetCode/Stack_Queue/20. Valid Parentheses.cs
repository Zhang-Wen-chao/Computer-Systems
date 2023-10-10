// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

using System.Collections.Generic;

public class Solution {
    public bool IsValid(string s) {
        Stack<char> stack = new Stack<char>();

        foreach (char c in s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.Push(c);
            } else {
                if (stack.Count == 0) return false;
                char top = stack.Pop();
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }

        return stack.Count == 0;
    }
}
public class Program {
    public static void Main() {
        Solution solution = new Solution();

        string input = "{[]}";
        bool result = solution.IsValid(input);

        Console.WriteLine($"Input: '{input}'");
        Console.WriteLine($"Is valid: {result}");
    }
}

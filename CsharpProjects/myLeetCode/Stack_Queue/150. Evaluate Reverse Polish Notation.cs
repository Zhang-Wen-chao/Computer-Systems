// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

using System.Collections.Generic;

public class Solution {
    public int EvalRPN(string[] tokens) {
        Stack<int> stack = new Stack<int>();

        foreach (string token in tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int operand2 = stack.Pop();
                int operand1 = stack.Pop();

                switch (token) {
                    case "+":
                        stack.Push(operand1 + operand2);
                        break;
                    case "-":
                        stack.Push(operand1 - operand2);
                        break;
                    case "*":
                        stack.Push(operand1 * operand2);
                        break;
                    case "/":
                        stack.Push(operand1 / operand2);
                        break;
                }
            } else {
                stack.Push(int.Parse(token));
            }
        }

        return stack.Peek();
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        string[] input = new string[] { "2", "1", "+", "3", "*" };
        int result = solution.EvalRPN(input);

        Console.WriteLine($"Input: {string.Join(" ", input)}");
        Console.WriteLine($"Output: {result}");
    }
}

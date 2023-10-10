// 151. Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/

public class Solution {
    public string ReverseWords(string s) {
        string[] words = s.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);
        Array.Reverse(words);
        return string.Join(" ", words);
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        string input = "  the sky is  blue  ";
        string result = solution.ReverseWords(input);
        
        Console.WriteLine($"Input: '{input}'");
        Console.WriteLine($"Output: '{result}'");
    }
}

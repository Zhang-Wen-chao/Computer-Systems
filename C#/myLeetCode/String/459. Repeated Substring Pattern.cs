// 459. Repeated Substring Pattern
// https://leetcode.com/problems/repeated-substring-pattern/

using System.Text;

public class Solution {
    public bool RepeatedSubstringPattern(string s) {
        int n = s.Length;
        for (int len = 1; len <= n / 2; len++) {
            if (n % len == 0) {  // Ensure the length is a factor of n
                int numRepeats = n / len;
                string pattern = s.Substring(0, len);
                StringBuilder concatenated = new StringBuilder();
                for (int i = 0; i < numRepeats; i++) {
                    concatenated.Append(pattern);
                }
                if (concatenated.ToString() == s) {
                    return true;
                }
            }
        }
        return false;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        string input = "abab";
        bool result = solution.RepeatedSubstringPattern(input);

        Console.WriteLine($"Does '{input}' have a repeated substring pattern? {result}");
    }
}

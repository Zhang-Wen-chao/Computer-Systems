// 28. Find the Index of the First Occurrence in a String
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

public class Solution {
    public int StrStr(string haystack, string needle) {
        if (string.IsNullOrEmpty(needle)) return 0;
        if (string.IsNullOrEmpty(haystack)) return -1;

        for (int i = 0; i <= haystack.Length - needle.Length; i++) {
            if (haystack.Substring(i, needle.Length) == needle) {
                return i;
            }
        }

        return -1;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();
        
        string haystack = "hello";
        string needle = "ll";
        
        int result = solution.StrStr(haystack, needle);
        Console.WriteLine($"The index of the first occurrence of '{needle}' in '{haystack}' is: {result}");
    }
}

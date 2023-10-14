// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

using System;

public class Solution {
    public bool IsAnagram(string s, string t) {
        if (s.Length != t.Length) {
            return false;
        }

        int[] charCount = new int[26];  // 为26个英文字母初始化计数数组

        for (int i = 0; i < s.Length; i++) {
            charCount[s[i] - 'a']++;  // 增加s中字符的计数
            charCount[t[i] - 'a']--;  // 减少t中字符的计数
        }

        // 打印计数数组的内容
        Console.WriteLine("Character counts:");
        for (int i = 0; i < 26; i++) {
            Console.WriteLine($"{(char)(i + 'a')}: {charCount[i]}");
        }

        // 如果两个字符串是字谜，那么计数数组中的所有值都应该是0
        foreach (int count in charCount) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();
        string s = "anagram";
        string t = "nagaram";
        Console.WriteLine($"Are \"{s}\" and \"{t}\" anagrams? {solution.IsAnagram(s, t)}");
    }
}

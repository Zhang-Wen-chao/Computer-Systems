// 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/

using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<string>> Partition(string s) {
        IList<IList<string>> result = new List<IList<string>>();
        List<string> current = new List<string>();
        PartitionHelper(s, 0, current, result);
        return result;
    }

    private void PartitionHelper(string s, int start, List<string> current, IList<IList<string>> result) {
        if (start == s.Length) {
            result.Add(new List<string>(current));
            return;
        }

        for (int end = start; end < s.Length; end++) {
            if (IsPalindrome(s, start, end)) {
                current.Add(s.Substring(start, end - start + 1));
                PartitionHelper(s, end + 1, current, result);
                current.RemoveAt(current.Count - 1);
            }
        }
    }

    private bool IsPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        string s = "aab";
        IList<IList<string>> result = solution.Partition(s);

        Console.WriteLine("All palindrome partitions:");
        foreach (var partition in result) {
            Console.WriteLine(string.Join(", ", partition));
        }
    }
}

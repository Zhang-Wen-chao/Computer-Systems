// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
using System;
using System.Collections.Generic;

public class Solution {
    public IList<string> LetterCombinations(string digits) {
        IList<string> combinations = new List<string>();
        if (string.IsNullOrEmpty(digits)) return combinations;

        string[] phoneMapping = new string[] {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        LetterCombinationsHelper(digits, phoneMapping, 0, "", combinations);

        return combinations;
    }

    private void LetterCombinationsHelper(string digits, string[] phoneMapping, int index, string current, IList<string> combinations) {
        if (index == digits.Length) {
            combinations.Add(current);
            return;
        }

        string letters = phoneMapping[digits[index] - '0'];
        foreach (char letter in letters) {
            LetterCombinationsHelper(digits, phoneMapping, index + 1, current + letter, combinations);
        }
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        string digits = "23";
        IList<string> combinations = solution.LetterCombinations(digits);

        Console.WriteLine($"Letter Combinations of {digits}:");
        foreach (string combination in combinations) {
            Console.WriteLine(combination);
        }
    }
}

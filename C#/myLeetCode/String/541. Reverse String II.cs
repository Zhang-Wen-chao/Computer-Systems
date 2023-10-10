// 541. Reverse String II
// https://leetcode.com/problems/reverse-string-ii/
public class Solution {
    public string ReverseStr(string s, int k) {
        char[] arr = s.ToCharArray();
        int n = arr.Length;
        
        for (int start = 0; start < n; start += 2 * k) {
            int i = start, j = Math.Min(start + k - 1, n - 1);
            while (i < j) {
                char tmp = arr[i];
                arr[i++] = arr[j];
                arr[j--] = tmp;
            }
        }
        
        return new string(arr);
    }
}
public class Program {
    public static void Main() {
        Solution solution = new Solution();

        string input = "abcdefg";
        int k = 2;
        string result = solution.ReverseStr(input, k);

        Console.WriteLine($"Input: '{input}' with k={k}");
        Console.WriteLine($"Output: '{result}'");
    }
}

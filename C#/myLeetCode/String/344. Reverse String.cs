// 344. Reverse String
// https://leetcode.com/problems/reverse-string/
public class Solution {
    public void ReverseString(char[] s) {
        int left = 0;
        int right = s.Length - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            left++;
            right--;
        }
    }
}
public class Program {
    public static void Main() {
        Solution solution = new Solution();

        char[] input = {'h', 'e', 'l', 'l', 'o'};
        solution.ReverseString(input);

        Console.WriteLine($"Reversed string: {new string(input)}");
    }
}

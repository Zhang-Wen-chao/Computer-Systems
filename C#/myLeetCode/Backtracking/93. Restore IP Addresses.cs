// 93. Restore IP Addresses
// https://leetcode.com/problems/restore-ip-addresses/

using System;
using System.Collections.Generic;

public class Solution {
    public IList<string> RestoreIpAddresses(string s) {
        IList<string> result = new List<string>();
        RestoreIpAddressesHelper(s, 0, new List<string>(), result);
        return result;
    }

    private void RestoreIpAddressesHelper(string s, int index, List<string> current, IList<string> result) {
        if (current.Count == 4 && index == s.Length) {
            result.Add(string.Join(".", current));
            return;
        }

        if (current.Count == 4 || index == s.Length) {
            return;
        }

        for (int i = 1; i <= 3 && index + i <= s.Length; i++) {
            string part = s.Substring(index, i);
            if ((part[0] == '0' && part.Length > 1) || (i == 3 && int.Parse(part) > 255)) {
                continue;
            }
            current.Add(part);
            RestoreIpAddressesHelper(s, index + i, current, result);
            current.RemoveAt(current.Count - 1);
        }
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        string s = "25525511135";
        IList<string> result = solution.RestoreIpAddresses(s);

        Console.WriteLine("All possible IP addresses:");
        foreach (var ip in result) {
            Console.WriteLine(ip);
        }
    }
}

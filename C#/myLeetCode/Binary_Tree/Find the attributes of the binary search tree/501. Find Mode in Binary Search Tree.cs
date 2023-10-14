// 501. Find Mode in Binary Search Tree
// https://leetcode.com/problems/find-mode-in-binary-search-tree/

using System;
using System.Collections.Generic;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    private int? prev = null;
    private int count = 1;
    private int max = 0;

    public int[] FindMode(TreeNode? root) {
        if (root == null) return new int[0];

        List<int> modes = new List<int>();
        Traverse(root, modes);

        return modes.ToArray();
    }

    private void Traverse(TreeNode? node, List<int> modes) {
        if (node == null) return;

        Traverse(node.left, modes);

        if (prev.HasValue) {
            if (node.val == prev.Value) count++;
            else count = 1;
        }

        if (count > max) {
            max = count;
            modes.Clear();
            modes.Add(node.val);
        } else if (count == max) {
            modes.Add(node.val);
        }

        prev = node.val;
        Traverse(node.right, modes);
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(1) {
            right = new TreeNode(2) {
                left = new TreeNode(2)
            }
        };

        int[] modes = solution.FindMode(tree);

        // 打印结果
        Console.WriteLine($"Modes in the BST: {string.Join(", ", modes)}");
    }
}

// 257. Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/

using System;
using System.Collections.Generic;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public IList<string> BinaryTreePaths(TreeNode? root) {
        IList<string> paths = new List<string>();
        if (root != null) {
            Traverse(root, "", paths);
        }
        return paths;
    }

    private void Traverse(TreeNode? node, string currentPath, IList<string> paths) {
        if (node == null) return;

        currentPath += node.val.ToString();
        if (node.left == null && node.right == null) {
            paths.Add(currentPath);
        } else {
            currentPath += "->";
            Traverse(node.left, currentPath, paths);
            Traverse(node.right, currentPath, paths);
        }
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(1) {
            left = new TreeNode(2) {
                right = new TreeNode(5)
            },
            right = new TreeNode(3)
        };

        IList<string> paths = solution.BinaryTreePaths(tree);

        // 打印结果
        Console.WriteLine("Paths:");
        foreach (var path in paths) {
            Console.WriteLine(path);
        }
    }
}

// 513. Find Bottom Left Tree Value
// https://leetcode.com/problems/find-bottom-left-tree-value/

using System;
using System.Collections.Generic;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public int FindBottomLeftValue(TreeNode? root) {
        if (root == null) return -1;

        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.Enqueue(root);

        TreeNode? currentNode = null;
        while (queue.Count > 0) {
            currentNode = queue.Dequeue();
            if (currentNode.right != null) queue.Enqueue(currentNode.right);
            if (currentNode.left != null) queue.Enqueue(currentNode.left);
        }

        return currentNode?.val ?? -1;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(2) {
            left = new TreeNode(1),
            right = new TreeNode(3)
        };

        int value = solution.FindBottomLeftValue(tree);

        // 打印结果
        Console.WriteLine($"Bottom left tree value: {value}");
    }
}

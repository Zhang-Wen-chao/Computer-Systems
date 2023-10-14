// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

using System;
using System.Collections.Generic;

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public IList<int> PostorderTraversal(TreeNode root) {
        IList<int> result = new List<int>();
        Postorder(root, result);
        return result;
    }

    private void Postorder(TreeNode node, IList<int> result) {
        if (node == null) return;

        Postorder(node.left, result);
        Postorder(node.right, result);
        result.Add(node.val);
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(1) {
            right = new TreeNode(2) {
                left = new TreeNode(3)
            }
        };

        IList<int> postorderTraversal = solution.PostorderTraversal(tree);

        Console.WriteLine("Postorder Traversal:");
        foreach (int val in postorderTraversal) {
            Console.Write(val + " ");
        }
    }
}

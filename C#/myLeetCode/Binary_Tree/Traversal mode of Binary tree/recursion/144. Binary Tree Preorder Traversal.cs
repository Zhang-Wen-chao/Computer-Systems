// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

using System;
using System.Collections.Generic;

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public IList<int> PreorderTraversal(TreeNode root) {
        IList<int> result = new List<int>();
        Preorder(root, result);
        return result;
    }

    private void Preorder(TreeNode node, IList<int> result) {
        if (node == null) return;

        result.Add(node.val);
        Preorder(node.left, result);
        Preorder(node.right, result);
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

        IList<int> preorderTraversal = solution.PreorderTraversal(tree);

        Console.WriteLine("Preorder Traversal:");
        foreach (int val in preorderTraversal) {
            Console.Write(val + " ");
        }
    }
}

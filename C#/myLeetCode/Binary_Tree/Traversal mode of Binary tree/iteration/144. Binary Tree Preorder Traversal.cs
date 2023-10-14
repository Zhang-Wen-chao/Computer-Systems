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
        if (root == null) return result;

        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.Push(root);

        while (stack.Count > 0) {
            TreeNode currentNode = stack.Pop();
            result.Add(currentNode.val);

            if (currentNode.right != null) {
                stack.Push(currentNode.right);
            }
            if (currentNode.left != null) {
                stack.Push(currentNode.left);
            }
        }

        return result;
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

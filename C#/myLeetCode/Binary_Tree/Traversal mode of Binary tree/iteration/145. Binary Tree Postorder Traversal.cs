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
        if (root == null) return result;

        Stack<TreeNode> stack1 = new Stack<TreeNode>();
        Stack<TreeNode> stack2 = new Stack<TreeNode>();
        stack1.Push(root);

        while (stack1.Count > 0) {
            TreeNode currentNode = stack1.Pop();
            stack2.Push(currentNode);

            if (currentNode.left != null) {
                stack1.Push(currentNode.left);
            }
            if (currentNode.right != null) {
                stack1.Push(currentNode.right);
            }
        }

        while (stack2.Count > 0) {
            result.Add(stack2.Pop().val);
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

        IList<int> postorderTraversal = solution.PostorderTraversal(tree);

        Console.WriteLine("Postorder Traversal:");
        foreach (int val in postorderTraversal) {
            Console.Write(val + " ");
        }
    }
}

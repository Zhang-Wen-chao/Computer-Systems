// 538. Convert BST to Greater Tree
// https://leetcode.com/problems/convert-bst-to-greater-tree/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    private int sum = 0;

    public TreeNode? ConvertBST(TreeNode? root) {  // 修改返回类型为 TreeNode?
        if (root == null) return null;

        ConvertBST(root.right);

        sum += root.val;
        root.val = sum;

        ConvertBST(root.left);

        return root;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(4) {
            left = new TreeNode(1) {
                left = new TreeNode(0),
                right = new TreeNode(2) {
                    right = new TreeNode(3)
                }
            },
            right = new TreeNode(6) {
                left = new TreeNode(5),
                right = new TreeNode(7) {
                    right = new TreeNode(8)
                }
            }
        };

        TreeNode? newTree = solution.ConvertBST(tree);  // 修改变量类型为 TreeNode?

        // 打印结果
        PrintTree(newTree);
    }

    public static void PrintTree(TreeNode? root) {
        if (root == null) return;

        PrintTree(root.left);
        Console.Write(root.val + " ");
        PrintTree(root.right);
    }
}

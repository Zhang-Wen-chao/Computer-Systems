// 404. Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public int SumOfLeftLeaves(TreeNode? root) {
        if (root == null) return 0;

        int sum = 0;
        if (root.left != null && root.left.left == null && root.left.right == null) {
            sum += root.left.val;
        }

        sum += SumOfLeftLeaves(root.left);
        sum += SumOfLeftLeaves(root.right);

        return sum;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(3) {
            left = new TreeNode(9),
            right = new TreeNode(20) {
                left = new TreeNode(15),
                right = new TreeNode(7)
            }
        };

        int sum = solution.SumOfLeftLeaves(tree);

        // 打印结果
        Console.WriteLine($"Sum of left leaves: {sum}");
    }
}

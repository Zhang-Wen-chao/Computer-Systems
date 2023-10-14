// 654. Maximum Binary Tree
// https://leetcode.com/problems/maximum-binary-tree/
// 简而言之: 根结点是数组中最大的，左子树的结点是数组中max左侧数组最大的值，右子树是max右侧。

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public TreeNode ConstructMaximumBinaryTree(int[] nums) {
        return Build(nums, 0, nums.Length - 1);
    }

    private TreeNode Build(int[] nums, int left, int right) {
        if (left > right) return null;

        int maxIndex = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        TreeNode root = new TreeNode(nums[maxIndex]);
        root.left = Build(nums, left, maxIndex - 1);
        root.right = Build(nums, maxIndex + 1, right);

        return root;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] nums = { 3, 2, 1, 6, 0, 5 };
        TreeNode tree = solution.ConstructMaximumBinaryTree(nums);

        // 打印结果
        PrintTree(tree);
    }

    public static void PrintTree(TreeNode? root) {
        if (root == null) return;

        PrintTree(root.left);
        Console.Write(root.val + " ");
        PrintTree(root.right);
    }
}

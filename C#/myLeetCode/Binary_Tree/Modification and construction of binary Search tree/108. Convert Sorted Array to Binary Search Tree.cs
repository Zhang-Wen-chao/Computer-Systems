// 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public TreeNode? SortedArrayToBST(int[] nums) {
        if (nums == null || nums.Length == 0) return null;
        return BuildTree(nums, 0, nums.Length - 1);
    }

    private TreeNode? BuildTree(int[] nums, int left, int right) {
        if (left > right) return null;

        int mid = left + (right - left) / 2;
        TreeNode node = new TreeNode(nums[mid]);
        node.left = BuildTree(nums, left, mid - 1);
        node.right = BuildTree(nums, mid + 1, right);

        return node;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] nums = {-10, -3, 0, 5, 9};
        TreeNode? tree = solution.SortedArrayToBST(nums);

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

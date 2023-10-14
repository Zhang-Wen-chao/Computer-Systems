// 450. Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst/
using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public TreeNode? DeleteNode(TreeNode? root, int key) {
        if (root == null) return null;

        if (key < root.val) {
            root.left = DeleteNode(root.left, key);
        } else if (key > root.val) {
            root.right = DeleteNode(root.right, key);
        } else {
            if (root.left == null) return root.right;
            if (root.right == null) return root.left;
            TreeNode? minNode = GetMin(root.right);
            if (minNode != null) {
                root.val = minNode.val;
                root.right = DeleteNode(root.right, minNode.val);
            }
        }
        return root;
    }

    private TreeNode? GetMin(TreeNode? node) {
        while (node?.left != null) node = node.left;
        return node;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(5) {
            left = new TreeNode(3) {
                left = new TreeNode(2),
                right = new TreeNode(4)
            },
            right = new TreeNode(6) {
                right = new TreeNode(7)
            }
        };

        int keyToDelete = 3;
        TreeNode? newTree = solution.DeleteNode(tree, keyToDelete);

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

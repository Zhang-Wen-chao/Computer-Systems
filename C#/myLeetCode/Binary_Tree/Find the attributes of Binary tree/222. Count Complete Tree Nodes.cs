// 222. Count Complete Tree Nodes
// https://leetcode.com/problems/count-complete-tree-nodes/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public int CountNodes(TreeNode? root) {
        if (root == null) return 0;

        int depth = ComputeDepth(root);
        if (depth == 0) return 1;

        int left = 1, right = (int)Math.Pow(2, depth) - 1;
        while (left <= right) {
            int pivot = left + (right - left) / 2;
            if (Exists(pivot, depth, root)) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }

        return (int)Math.Pow(2, depth) - 1 + left;
    }

    private int ComputeDepth(TreeNode? node) {
        int depth = 0;
        while (node?.left != null) {
            node = node.left;
            depth++;
        }
        return depth;
    }

    private bool Exists(int idx, int depth, TreeNode? node) {
        int left = 0, right = (int)Math.Pow(2, depth) - 1;
        for (int i = 0; i < depth; i++) {
            int pivot = left + (right - left) / 2;
            if (idx <= pivot) {
                node = node?.left;
                right = pivot;
            } else {
                node = node?.right;
                left = pivot + 1;
            }
        }
        return node != null;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(1) {
            left = new TreeNode(2) {
                left = new TreeNode(4),
                right = new TreeNode(5)
            },
            right = new TreeNode(3) {
                left = new TreeNode(6)
            }
        };

        int count = solution.CountNodes(tree);

        // 打印结果
        Console.WriteLine($"Total nodes in the tree: {count}");
    }
}

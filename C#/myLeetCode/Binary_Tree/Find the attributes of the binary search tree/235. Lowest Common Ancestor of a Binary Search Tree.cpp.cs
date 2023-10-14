// 235. Lowest Common Ancestor of a Binary Search Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
/*
这两个题目的区别是，235 题是给定一个二叉搜索树，而 236 题是给定一个普通的二叉树。二叉搜索树是一种特殊的二叉树，它满足以下性质：

对于任意一个节点，它的左子树的所有节点的值都小于它，它的右子树的所有节点的值都大于它。
它的中序遍历是一个升序序列。
因此，对于 235 题，我们可以利用二叉搜索树的性质，从根节点开始，比较它的值和 p 和 q 的值。如果它的值大于 p 和 q 的值，说明 p 和 q 都在它的左子树中，那么我们就递归地在左子树中查找 LCA。如果它的值小于 p 和 q 的值，说明 p 和 q 都在它的右子树中，那么我们就递归地在右子树中查找 LCA。如果都不满足，说明 p 和 q 分别在它的左右子树中，或者其中一个就是它本身，那么它就是 LCA。这个方法的时间复杂度是 O(H)，空间复杂度是 O(H)，其中 H 是二叉搜索树的高度1。

而对于 236 题，我们不能利用二叉搜索树的性质，因为普通的二叉树没有这样的排序规则。我们只能从根节点开始，递归地在左右子树中查找 p 和 q。如果在某个子树中找到了两个节点，那么这个子树的根节点就是 LCA。如果只在一个子树中找到了一个节点，那么这个节点就是 LCA。如果都没有找到，那么返回空指针。这个方法的时间复杂度是 O(N)，空间复杂度是 O(N)，其中 N 是二叉树的节点数2。
*/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public TreeNode? LowestCommonAncestor(TreeNode? root, TreeNode p, TreeNode q) { // 注意这里移除了 p 和 q 的可空标记
        while (root != null) {
            if (root.val > p.val && root.val > q.val) {
                root = root.left;
            } else if (root.val < p.val && root.val < q.val) {
                root = root.right;
            } else {
                return root;
            }
        }
        return null;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(6) {
            left = new TreeNode(2) {
                left = new TreeNode(0),
                right = new TreeNode(4) {
                    left = new TreeNode(3),
                    right = new TreeNode(5)
                }
            },
            right = new TreeNode(8) {
                left = new TreeNode(7),
                right = new TreeNode(9)
            }
        };

        TreeNode p = tree.left;  // Node with value 2
        TreeNode q = tree.right; // Node with value 8

        TreeNode? lca = solution.LowestCommonAncestor(tree, p, q);

        // 打印结果
        Console.WriteLine($"Lowest Common Ancestor of {p.val} and {q.val} is: {lca?.val}");
    }
}

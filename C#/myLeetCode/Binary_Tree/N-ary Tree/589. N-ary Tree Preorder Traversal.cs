// 589. N-ary Tree Preorder Traversal
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

using System;
using System.Collections.Generic;

public class Node {
    public int val;
    public IList<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
        children = new List<Node>();
    }

    public Node(int _val, IList<Node> _children) {
        val = _val;
        children = _children;
    }
}

public class Solution {
    public IList<int> Preorder(Node root) {
        List<int> result = new List<int>();
        PreorderTraversal(root, result);
        return result;
    }

    private void PreorderTraversal(Node node, List<int> result) {
        if (node == null) {
            return;
        }

        result.Add(node.val);

        foreach (var child in node.children) {
            PreorderTraversal(child, result);
        }
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        Node tree = new Node(1, new List<Node> {
            new Node(3, new List<Node> {
                new Node(5),
                new Node(6)
            }),
            new Node(2),
            new Node(4)
        });

        IList<int> preorderTraversal = solution.Preorder(tree);

        Console.WriteLine("Preorder Traversal:");
        foreach (int val in preorderTraversal) {
            Console.Write(val + " ");
        }
    }
}

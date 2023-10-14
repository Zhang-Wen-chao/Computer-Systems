// 590. N-ary Tree Postorder Traversal
// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

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
    public IList<int> Postorder(Node root) {
        List<int> result = new List<int>();
        PostorderTraversal(root, result);
        return result;
    }

    private void PostorderTraversal(Node node, List<int> result) {
        if (node == null) {
            return;
        }

        foreach (var child in node.children) {
            PostorderTraversal(child, result);
        }

        result.Add(node.val);
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

        IList<int> postorderTraversal = solution.Postorder(tree);

        Console.WriteLine("Postorder Traversal:");
        foreach (int val in postorderTraversal) {
            Console.Write(val + " ");
        }
    }
}

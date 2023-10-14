// 559. Maximum Depth of N-ary Tree
// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

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
    public int MaxDepth(Node root) {
        if (root == null) {
            return 0;
        }

        int maxChildDepth = 0;
        foreach (var child in root.children) {
            int childDepth = MaxDepth(child);
            maxChildDepth = Math.Max(maxChildDepth, childDepth);
        }

        return maxChildDepth + 1;
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

        int maxDepth = solution.MaxDepth(tree);
        Console.WriteLine($"Maximum Depth of N-ary Tree: {maxDepth}");
    }
}

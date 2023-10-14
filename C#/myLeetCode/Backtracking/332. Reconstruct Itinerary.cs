// 332. Reconstruct Itinerary
// https://leetcode.com/problems/reconstruct-itinerary/

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public IList<string> FindItinerary(IList<IList<string>> tickets) {
        Dictionary<string, List<string>> graph = new Dictionary<string, List<string>>();
        List<string> result = new List<string>();

        // 构建图
        foreach (var ticket in tickets) {
            string from = ticket[0];
            string to = ticket[1];
            if (!graph.ContainsKey(from)) {
                graph[from] = new List<string>();
            }
            graph[from].Add(to);
        }

        // 对图中的每个节点的目的地列表按字母顺序排序
        foreach (var kvp in graph) {
            kvp.Value.Sort();
        }

        // 从"JFK"出发开始深度优先搜索
        DFS(graph, "JFK", result);

        // 结果中反转行程，因为深度优先搜索是逆序的
        result.Reverse();

        return result;
    }

    private void DFS(Dictionary<string, List<string>> graph, string current, List<string> result) {
        if (graph.ContainsKey(current) && graph[current].Any()) {
            List<string> destinations = graph[current];
            while (destinations.Any()) {
                string nextDestination = destinations[0];
                destinations.RemoveAt(0);
                DFS(graph, nextDestination, result);
            }
        }
        result.Add(current);
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        IList<IList<string>> tickets = new List<IList<string>> {
            new List<string> { "MUC", "LHR" },
            new List<string> { "JFK", "MUC" },
            new List<string> { "SFO", "SJC" },
            new List<string> { "LHR", "SFO" }
        };

        IList<string> result = solution.FindItinerary(tickets);

        // 打印结果
        Console.WriteLine(string.Join(" -> ", result));
    }
}

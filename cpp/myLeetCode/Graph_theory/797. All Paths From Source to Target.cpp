// 797. All Paths From Source to Target
// https://leetcode.com/problems/all-paths-from-source-to-target/

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;

        int targetNode = graph.size() - 1;

        dfs(graph, 0, targetNode, path, result);

        return result;
    }

private:
    void dfs(std::vector<std::vector<int>>& graph, int currNode, int targetNode, std::vector<int>& path, std::vector<std::vector<int>>& result) {
        path.push_back(currNode);

        if (currNode == targetNode) {
            result.push_back(path);
        } else {
            for (int nextNode : graph[currNode]) {
                dfs(graph, nextNode, targetNode, path, result);
            }
        }

        path.pop_back();
    }
};

int main() {
    std::vector<std::vector<std::vector<int>>> testCases = {
        {{1,2}, {3}, {3}, {}},
        {{4,3,1},{3,2,4},{3},{4},{}}
    };

    Solution solution;

    for (int i = 0; i < testCases.size(); i++) {
        std::vector<std::vector<int>> graph = testCases[i];

        std::vector<std::vector<int>> result = solution.allPathsSourceTarget(graph);

        std::cout << "All paths from source to target for test case " << (i + 1) << ":" << std::endl;
        for (int j = 0; j < result.size(); j++) {
            std::cout << "Path " << (j + 1) << ": ";
            for (int k = 0; k < result[j].size(); k++) {
                std::cout << result[j][k] << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
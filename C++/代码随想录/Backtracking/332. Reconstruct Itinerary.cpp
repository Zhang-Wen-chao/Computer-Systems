// 332. Reconstruct Itinerary
// https://leetcode.com/problems/reconstruct-itinerary/

#include <unordered_map>
#include <algorithm>
#include <set>
#include "../printUtils.hpp"

class Solution {
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
        std::unordered_map<std::string, std::multiset<std::string>> graph;
        std::vector<std::string> itinerary;

        // 构建邻接表
        for (const auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        dfs(graph, "JFK", itinerary);

        // 结果是逆序的，需要反转
        std::reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }

private:
    void dfs(std::unordered_map<std::string, std::multiset<std::string>>& graph, const std::string& airport,
             std::vector<std::string>& itinerary) {
        while (!graph[airport].empty()) {
            auto nextAirport = *(graph[airport].begin());
            graph[airport].erase(graph[airport].begin());
            dfs(graph, nextAirport, itinerary);
        }

        itinerary.push_back(airport);
    }
};

int main() {
    std::vector<std::vector<std::string>> tickets1 = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    printArray(Solution().findItinerary(tickets1));

    std::vector<std::vector<std::string>> tickets2 = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"},
                                                      {"ATL", "JFK"}, {"ATL", "SFO"}};
    printArray(Solution().findItinerary(tickets2));

    return 0;
}
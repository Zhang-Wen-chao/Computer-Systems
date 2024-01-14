from collections import defaultdict

def findItinerary(tickets):
    graph = defaultdict(list)
    for src, dst in sorted(tickets)[::-1]:
        graph[src].append(dst)

    route = []

    def visit(airport):
        while graph[airport]:
            next_airport = graph[airport].pop()
            visit(next_airport)
        route.append(airport)

    visit("JFK")
    return route[::-1]

# 测试用例
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
print(findItinerary(tickets))

def allPathsSourceTarget(graph):
    def dfs(node, path):
        if node == len(graph) - 1:
            result.append(path)
            return
        for next_node in graph[node]:
            dfs(next_node, path + [next_node])

    result = []
    dfs(0, [0])
    return result

# 测试用例
graph = [[1,2], [3], [3], []]
print(allPathsSourceTarget(graph))

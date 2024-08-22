from typing import List

class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        parent = list(range(n - 1))  # 初始化每个节点的父节点为其自身
        print(f"Initial parent array: {parent}")

        # 非递归的并查集查找函数，查找节点x的根节点
        def find(x: int) -> int:
            root = x
            while parent[root] != root:
                root = parent[root]
            while parent[x] != root:
                parent[x], x = root, parent[x]
            return root

        result = []
        connected_components = n - 1  # 初始连通分量个数（即 n-1 个边）

        for left, right in queries:
            print(f"\nProcessing query: connect [{left}, {right}]")
            right_root = find(right - 1)  # 查找右边界的根节点
            current = find(left)  # 从左边界开始查找
            
            # 将左边界到右边界之间的所有节点连接到右边界的根节点
            while current < right - 1:
                connected_components -= 1  # 每次连接成功连通分量减1
                print(f"Connecting node {current} to {right - 1} (root {right_root})")
                parent[current] = right_root  # 连接当前节点到右边界的根节点
                current = find(current + 1)  # 查找下一个节点
                print(f"Updated parent array: {parent}")

            result.append(connected_components)
            print(f"Connected components after query: {connected_components}")
        
        print(f"\nFinal result: {result}")
        return result

# 示例使用
solution = Solution()
n = 5
queries = [[2, 4], [0, 2], [0, 4]]
solution.shortestDistanceAfterQueries(n, queries)


# 下面是吴凯峰的代码
# n = 5
# queries = [[0,2], [0,3], [0,4]]
# def min_path(n,queries):
#     def dfs(i, start, end):
#         if i == 1:
#             return 0
#         r = float('inf')
#         idx = [index for index, element in enumerate(end) if element == i]
#         for id in idx:
#             r = min(dfs(start[id],  start, end), r)
#         r = min(dfs(i - 1,  start, end), r)
#         r += 1
#         return r
#     result = []
#     for i in range(len(queries)):
#         query = queries[:i+1]
#         start = [x[0] + 1 for x in query]
#         end = [x[1] + 1 for x in query]
#         ans = dfs(n,  start, end)
#         result.append(ans)
#     return result

# a = min_path(n, queries)
# print(a)

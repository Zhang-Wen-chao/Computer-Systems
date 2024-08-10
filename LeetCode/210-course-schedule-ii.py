from collections import defaultdict, deque

def findOrder(numCourses, prerequisites):
    # 创建图和入度表
    graph = defaultdict(list)
    in_degree = [0] * numCourses

    # 填充图和入度表
    for dest, src in prerequisites:
        graph[src].append(dest)
        in_degree[dest] += 1

    # 初始化队列，将所有入度为0的节点入队
    queue = deque([i for i in range(numCourses) if in_degree[i] == 0])
    order = []

    # BFS遍历图
    while queue:
        course = queue.popleft()
        order.append(course)

        # 遍历当前课程的邻居节点，将其入度减1
        for neighbor in graph[course]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)

    # 如果order的长度等于numCourses，表示可以完成所有课程
    if len(order) == numCourses:
        return order
    else:
        return []

# 示例
numCourses = 4
prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]
print(findOrder(numCourses, prerequisites))  # 输出: [0, 1, 2, 3] 或 [0, 2, 1, 3]

from collections import deque, defaultdict

def canFinish(numCourses, prerequisites):
    # 创建图和入度表
    graph = defaultdict(list)
    in_degree = [0] * numCourses

    # 填充图和入度表
    for dest, src in prerequisites:
        graph[src].append(dest)
        in_degree[dest] += 1

    # 初始化队列，将所有入度为0的节点入队
    queue = deque([i for i in range(numCourses) if in_degree[i] == 0])
    visited_courses = 0

    # BFS遍历图
    while queue:
        course = queue.popleft()
        visited_courses += 1

        # 遍历当前课程的邻居节点，将其入度减1
        for neighbor in graph[course]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)

    # 判断是否所有课程都被访问过
    return visited_courses == numCourses

# 示例
numCourses = 4
prerequisites = [[1, 0], [2, 1], [3, 2]]
print(canFinish(numCourses, prerequisites))  # 输出: True

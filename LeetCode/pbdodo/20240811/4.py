# 在一个简单的哈希表实现中，对于给定哈希函数 f(x) = x % n，有一长度为 n 的数组用于存储 x（x ≥ 0）值。
# 当需要向哈希表插入一个值（x）时，从数组的下标（f(x)）开始，向右循环移动，找到第一个未存储过数字的位置，写入（x）。
# 若哈希表已满或（x）已存在于表中，则不再插入 x。
# 给定（n）个整数 a_i（a_i ≥ -1）表示哈希表数组中存储的元素，-1表示当前位置未写入数据。
# 请按插入哈希表的顺序输出原序列（假设插入过程中不存在相同的数字），如果有多个满足条件的序列，输出字典序最小的。

# 输入描述
# 第一行为一个正整数（n），第二行为（n）个整数（a1，a2，•••，an），含义如题。
# 输入保证序列为通过线性性探测插入的哈希表结果。（除a_i = -1 外，其它数字两两互不相等。）
# 输出描述
# 输出 l 个非负整数，表示插入哈希表的原序列，其中（l）为哈希表中非（-1）的整数个数。
# 补充说明
# • 对于 30％ 的数据，（1 ≤ n ≤ 10）；
# • 对于 60% 的数据，（1 ≤ n ≤ 1000）；
# • 对于 100% 的数据，（1 ≤ n ≤ 10^5），（-1 ≤ a_i ≤ 10^9）。

# input 1:
# 5
# -1 1 -1 3 4
# output 1:
# 1 3 4
# 由于没有冲突，原序列可以是（［1,3,4］）的任意一种排列组合，而其中（I1,3,4］） 是所有可能的结果中字典序最小的一种。

import heapq

# 读取输入
n = int(input())
hash_table = list(map(int, input().split()))

# 构建图和入度数组
graph = [[] for _ in range(n)]
indegree = [0 for _ in range(n)]

# 获取所有非 -1 的节点和对应位置
nodes = [(hash_table[i], i) for i in range(n) if hash_table[i] != -1]
nodes.sort()  # 按值排序，方便后续字典序处理

# 构建图，确定每个节点的依赖关系
for value, current_pos in nodes:
    ideal_pos = value % n
    while ideal_pos != current_pos:
        graph[ideal_pos].append(current_pos)
        indegree[current_pos] += 1
        ideal_pos = (ideal_pos + 1) % n

# 优先队列存储所有入度为 0 的节点（字典序最小的在前）
min_heap = [(value, current_pos) for value, current_pos in nodes if indegree[current_pos] == 0]

# 结果存储
result = []

# 拓扑排序，按字典序最小输出
while min_heap:
    value, pos = heapq.heappop(min_heap)
    result.append(value)
    for neighbor in graph[pos]:
        indegree[neighbor] -= 1
        if indegree[neighbor] == 0:
            heapq.heappush(min_heap, (hash_table[neighbor], neighbor))

# 输出结果
print(result)
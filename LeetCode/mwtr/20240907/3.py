import sys
from collections import defaultdict

sys.setrecursionlimit(200000)

def dfs(node, parent, tree, children_count):
    # 统计每个节点的直接子节点数量
    count = 0
    for child in tree[node]:
        if child != parent:  # 确保不回到父节点
            count += 1
            dfs(child, node, tree, children_count)
    children_count[node] = count  # 直接子节点数量
    return

def solve():
    T = int(input())  # 读取测试数据组数
    for _ in range(T):
        n = int(input())  # 读取每组的节点数量
        tree = defaultdict(list)
        
        # 构建树
        for _ in range(n - 1):
            u, v = map(int, input().split())
            tree[u].append(v)
            tree[v].append(u)
        
        # 打印树的结构
        print("树的结构：")
        for node in tree:
            print(f"节点 {node} 连接的节点: {tree[node]}")
        
        children_count = [0] * (n + 1)  # 记录每个节点的直接子节点数量
        
        # 从根节点1开始进行DFS，计算每个节点的直接子节点数量
        dfs(1, -1, tree, children_count)
        
        # 打印每个节点的直接子节点数量
        print(f"直接子节点数量: {children_count[1:n+1]}")
        
        # 统计每类子节点数量的节点个数
        count_0 = 0  # 记录子节点数为 0 的节点数（叶子节点）
        count_1 = 0  # 记录子节点数为 1 的节点数
        count_2 = 0  # 记录子节点数为 2 的节点数
        
        for i in range(1, n + 1):
            if children_count[i] == 0:
                count_0 += 1
            elif children_count[i] == 1:
                count_1 += 1
            elif children_count[i] == 2:
                count_2 += 1
        
        # 打印每类子节点的数量
        print(f"子节点数为 0 的节点数: {count_0}")
        print(f"子节点数为 1 的节点数: {count_1}")
        print(f"子节点数为 2 的节点数: {count_2}")
        
        # 计算组合数 C(n, 2) = n * (n - 1) / 2
        similar_pairs_0 = count_0 * (count_0 - 1) // 2 if count_0 > 1 else 0
        similar_pairs_1 = count_1 * (count_1 - 1) // 2 if count_1 > 1 else 0
        similar_pairs_2 = count_2 * (count_2 - 1) // 2 if count_2 > 1 else 0
        
        # 打印每类节点的组合数
        print(f"子节点数为 0 的组合数: {similar_pairs_0}")
        print(f"子节点数为 1 的组合数: {similar_pairs_1}")
        print(f"子节点数为 2 的组合数: {similar_pairs_2}")
        
        # 最终相似节点对数为三部分相加
        similar_pairs = similar_pairs_0 + similar_pairs_1 + similar_pairs_2
        
        # 输出每组的结果
        print(f"相似节点对数: {similar_pairs}")

# 运行解决方案
solve()

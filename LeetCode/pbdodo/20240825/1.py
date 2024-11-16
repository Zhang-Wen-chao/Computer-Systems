def process_input():
    # 读取并处理输入
    T = int(input())  # 读取测试组数
    test_cases = []
    
    for _ in range(T):
        n = int(input())  # 读取节点数
        v = list(map(int, input().split()))  # 读取正整数序列
        edges = []
        for _ in range(n - 1):
            a, b, w = map(int, input().split())  # 读取边的信息
            edges.append((w, a, b))
        test_cases.append((n, v, edges))
    
    return test_cases

def max_score(n, v, edges):
    # 计算最大得分的核心逻辑
    edges.sort(reverse=True, key=lambda x: x[0])  # 按边权值从大到小排序
    
    parent = list(range(n + 1))  # 初始化并查集
    size = [1] * (n + 1)  # 初始化每个连通块的大小
    
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]
    
    def union(x, y):
        rootX = find(x)
        rootY = find(y)
        if rootX != rootY:
            parent[rootX] = rootY
            size[rootY] += size[rootX]
            return True
        return False
    
    max_score = v[-1]  # 初始得分，全独立节点（最多连通块的得分）
    current_weight_sum = 0  # 当前保留的边权和
    current_blocks = n  # 当前的连通块数量
    
    for w, a, b in edges:
        if union(a, b):  # 如果a和b可以连通
            current_weight_sum += w  # 增加边权和
            current_blocks -= 1  # 连通块数量减少
            max_score = max(max_score, current_weight_sum + v[current_blocks-1])
    
    return max_score

def main():
    test_cases = process_input()  # 读取并处理输入
    results = []
    for n, v, edges in test_cases:
        results.append(max_score(n, v, edges))  # 计算每组数据的最大得分
    for result in results:
        print(result)  # 输出结果

if __name__ == "__main__":
    main()

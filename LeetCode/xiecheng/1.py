def max_treasure_value(n, m, k):
    # 初始化 dp 数组
    dp = [[[-1 for _ in range(m)] for _ in range(n)] for _ in range(k+1)]
    
    # 起点初始化
    dp[0][0][0] = 0
    
    # 遍历步数
    for step in range(1, k+1):
        for i in range(n):
            for j in range(m):
                if dp[step-1][i][j] == -1: continue
                
                # 上下左右四个方向
                directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
                
                for dx, dy in directions:
                    ni, nj = i + dx, j + dy
                    
                    # 检查是否超出边界
                    if not (0 <= ni < n and 0 <= nj < m): continue
                    
                    # 更新 dp 值
                    newValue = dp[step-1][i][j] + nj + ni * m
                    if dp[step][ni][nj] == -1 or dp[step][ni][nj] < newValue:
                        dp[step][ni][nj] = newValue
                        
    # 寻找 k 步内最大值
    maxValue = -1
    for i in range(n):
        for j in range(m):
            if dp[k][i][j] > maxValue:
                maxValue = dp[k][i][j]
                
    return maxValue

def solve_queries():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    q = int(data.pop(0))
    results = []
    
    for _ in range(q):
        n = int(data.pop(0))
        m = int(data.pop(0))
        k = int(data.pop(0))
        
        result = max_treasure_value(n, m, k)
        results.append(result)
        
    return results

results = solve_queries()
for result in results:
    print(result)
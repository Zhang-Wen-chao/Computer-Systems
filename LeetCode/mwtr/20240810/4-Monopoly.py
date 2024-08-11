# 小美在玩大富翁游戏，游戏中有n+1个城市排成一排，编号从0到n,第i个城市上有一个数字ai,表示达到第i个城市可以获得ai枚金币。
# 每一轮开始小美会获得4张卡牌，分别可以跳跃1、2、3、4个城市，例如小美可以从城市1跳跃3个城市到城市4.当小美使用完这4张卡牌后，会开启新的一轮。
# 初始时，小美拥有0枚金币，在任意时刻，小美的金币数量都必须大于等于0，小美想知道它从第0个城市出发，到第n个城市最多可以获得多少枚金币。
# 输入：
# 10
# -1 2 3 4 -9 -9 -1 3 -1 -1
# 输出：
# 9
# 说明：输入第一行是城市个数，第二行是到达城市1到n可以获得的金币数量。输出是金币数量，如果无法到达第n个城市则输出-1。
# 最优的方法：
# 第一步：使用跳跃3的卡牌，从0到3，获得3枚金币；
# 第二部：使用跳跃1的卡牌，从3到4，获得4枚金币；
# 第三步：使用跳跃4的卡牌，从4到8，获得3枚金币；
# 第4步：使用跳跃2的卡牌， 从8跳到10，获得-1枚金币；
# 共计9枚金币

# 状态压缩动态规划，就是我们俗称的状压DP，是利用计算机二进制的性质来描述状态的一种DP方式。

def max_coins(n, coins):
    dp = [[-float('inf')] * 16 for _ in range(n + 1)]
    dp[0][0] = 0
    
    for i in range(n):
        for mask in range(16):
            if dp[i][mask] == -float('inf'):
                continue
            for j in range(1, 5):
                if i + j <= n:
                    if not (mask & (1 << (j - 1))):  # 确保卡牌j未使用
                        new_mask = mask | (1 << (j - 1))
                        new_coins = dp[i][mask] + coins[i + j - 1]
                        if new_coins >= 0:  # 确保金币数量不为负
                            dp[i + j][new_mask] = max(dp[i + j][new_mask], new_coins)
    
    max_coins = max(dp[n])
    return max_coins if max_coins != -float('inf') else -1

# 示例输入
n = 10
coins = [-1, 2, 3, 4, -9, -9, -1, 3, -1, -1]

# 输出结果
result = max_coins(n, coins)
print(result)  # 应该输出 9

# T = int(input())
# results = []

# for i in range(T):
#     n = int(input())
#     coins = list(map(int, input().split()))
#     results.append(max_coins(n, coins))

# for result in results:
#     print(result)
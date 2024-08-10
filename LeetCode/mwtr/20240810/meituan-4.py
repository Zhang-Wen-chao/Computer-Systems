def max_coins(n, coins):
    coins[:0] = [0, 0, 0, 0]  # 在coins前面插入4个0，方便处理边界情况
    # dp[i][mask]表示到达城市i时，使用了某个跳跃组合(mask)能获得的最大金币
    dp = [[-float('inf')] * 16 for _ in range(n + 1)]
    dp[0][0] = 0  # 初始时在城市0，金币数量为0，且未使用任何跳跃
    # 遍历每个城市
    for i in range(n):
        for mask in range(16):  # 遍历所有跳跃组合
            if dp[i][mask] == -float('inf'):
                continue  # 跳过无法到达的状态
            # 对于当前城市，检查可以跳跃的1到4个城市
            for j in range(1, 5):
                new_mask = mask | (1 << (j - 1))  # 更新mask，表示使用了j这个跳跃
                if (mask & (1 << (j - 1))) == 0 and i + j <= n:  # 检查j跳跃是否已经使用过
                    dp[i + j][new_mask] = max(dp[i + j][new_mask], dp[i][mask] + coins[i + j])
    # 查找使用了4次跳跃(对应mask中有4个1)的最大金币值
    result = max(dp[n])
    return result if result >= 0 else -1
# 输入
# n = int(input())
# coins = list(map(int, input().split()))
# # 输出结果
# print(max_coins(n, coins))

n = 10
coins = [-1, 2, 3, 4, -9, -9, -1, 3, -1, -1]
print(max_coins(n, coins)) # 9
# n = int(input())
# a = list(map(int, input().split()))
# print(max_gold(n, a))
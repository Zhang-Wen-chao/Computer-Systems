def solve():
    n, m = map(int, input().split())  # 读取关卡数量 n 和 英桀数量 m
    extra_reward = list(map(int, input().split()))  # 每位英桀的额外奖励
    levels = []

    # 读取每个关卡的奖励和来源
    for _ in range(n):
        ai = list(map(int, input().split()))  # 三个奖励的能力值
        bi = list(map(int, input().split()))  # 三个奖励的来源
        levels.append((ai, bi))

    # dp[mask][j] 表示在状态 mask 下，选择 j 位英桀的奖励次数下的最大得分
    dp = [[-float('inf')] * (1 << n) for _ in range(m)]
    dp_0 = [[0] * (1 << n) for _ in range(m)]  # 每位英桀获得奖励次数的初始化

    # 初始状态，未选择任何关卡，初始得分应为 0
    for j in range(m):
        dp[j][0] = 0

    # 遍历所有状态
    for mask in range(1 << n):
        # 处理每个状态的当前奖励
        for i in range(n):
            if (mask >> i) & 1 == 0:  # 如果关卡 i 还没有被选择
                ai, bi = levels[i]  # 当前关卡的奖励和来源
                for j in range(3):
                    new_mask = mask | (1 << i)  # 更新选择后的关卡状态
                    reward_source = bi[j] - 1  # 奖励来源的英桀
                    # 如果该奖励来源已经获得了3次及以上，则触发额外奖励
                    if dp_0[reward_source][mask] + 1 >= 3:
                        dp[reward_source][new_mask] = max(
                            dp[reward_source][new_mask],
                            dp[reward_source][mask] + ai[j] + extra_reward[reward_source]
                        )
                    else:
                        dp[reward_source][new_mask] = max(
                            dp[reward_source][new_mask],
                            dp[reward_source][mask] + ai[j]
                        )
                    # 更新获得奖励的次数
                    dp_0[reward_source][new_mask] = dp_0[reward_source][mask] + 1

    # 计算最终最大值
    max_value = 0
    for mask in range(1 << n):
        for j in range(m):
            max_value = max(max_value, dp[j][mask])

    print(max_value)

# 运行解决方案
solve()

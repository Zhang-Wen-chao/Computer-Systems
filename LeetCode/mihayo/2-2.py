def solve():
    n, m = map(int, input().split())  # 读取关卡数量 n 和 英桀数量 m
    extra_reward = list(map(int, input().split()))  # 每位英桀的额外奖励
    levels = []

    # 读取每个关卡的奖励和来源
    for _ in range(n):
        ai = list(map(int, input().split()))  # 三个奖励的能力值
        bi = list(map(int, input().split()))  # 三个奖励的来源
        levels.append((ai, bi))

    # dp[mask] 表示在状态 mask 下的最大能力值
    dp = [-float('inf')] * (1 << n)
    dp[0] = 0  # 初始状态，未选择任何关卡时的得分为 0

    # 记录每个状态下各英桀获得的奖励次数
    count = [[0] * m for _ in range(1 << n)]

    # 遍历所有状态
    for mask in range(1 << n):
        # 遍历所有关卡
        for i in range(n):
            if (mask >> i) & 1 == 0:  # 如果关卡 i 还没有被选择
                ai, bi = levels[i]  # 当前关卡的奖励和来源
                new_mask = mask | (1 << i)  # 更新选择后的关卡状态

                # 遍历当前关卡的三个奖励
                for j in range(3):
                    reward_source = bi[j] - 1  # 奖励来源的英桀

                    # 更新奖励次数
                    new_count = count[mask][:]  # 复制当前状态下的奖励次数
                    new_count[reward_source] += 1

                    # 计算新的得分
                    reward_value = dp[mask] + ai[j]

                    # 如果该英桀已经获得了3次奖励，则增加额外奖励
                    if new_count[reward_source] == 3:
                        reward_value += extra_reward[reward_source]

                    # 更新新状态的最大得分
                    if reward_value > dp[new_mask]:
                        dp[new_mask] = reward_value
                        count[new_mask] = new_count  # 更新新状态的奖励次数

    # 计算最终的最大得分
    print(max(dp))

# 运行解决方案
solve()

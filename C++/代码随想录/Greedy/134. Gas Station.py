def canCompleteCircuit(gas, cost):
    if sum(gas) < sum(cost):
        return -1

    start, total_gas = 0, 0
    for i in range(len(gas)):
        total_gas += gas[i] - cost[i]
        if total_gas < 0:
            start = i + 1
            total_gas = 0

    return start

# 测试用例
gas = [1,2,3,4,5]
cost = [3,4,5,1,2]
print(canCompleteCircuit(gas, cost))  # 输出应该是 3

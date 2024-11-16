def expected_sum(a, b):
    # 初始化两个操作前的数
    possible_sums = []
    
    # 模拟所有的操作可能
    for i in range(2):  # 第一次选择 a 或 b
        for j in range(2):  # 第二次选择 a 或 b
            a_tmp, b_tmp = a, b
            if i == 0:
                a_tmp *= 2
            else:
                b_tmp *= 2
            
            if j == 0:
                a_tmp *= 2
            else:
                b_tmp *= 2
            
            # 计算每种情况下的 a+b 之和
            possible_sums.append(a_tmp + b_tmp)
    
    # 计算期望值
    expected_value = sum(possible_sums) / len(possible_sums)
    return expected_value

# 输入示例
a, b = map(int, input().split())
result = expected_sum(a, b)

# 输出保留两位小数
print(f"{result:.2f}")

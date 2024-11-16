def count_4_and_6(num):
    # 将数字转换为字符串，统计'4'和'6'的出现次数
    return str(num).count('4') + str(num).count('6')

def solve():
    n, m = map(int, input().split())  # 读取输入的n和m
    max_count = 0
    result = 0
    
    for i in range(n, m + 1):
        count = count_4_and_6(i)  # 统计每个数字中'4'和'6'的数量
        # 如果当前数字的数量比max_count大，或者相等但数字本身更大，则更新结果
        if count > max_count or (count == max_count and i > result):
            max_count = count
            result = i
    
    print(result)

# 运行解决方案
solve()

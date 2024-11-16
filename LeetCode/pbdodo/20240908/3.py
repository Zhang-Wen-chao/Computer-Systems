from collections import defaultdict

# 计算所有可能的相似子数组，并更新哈希表
def get_similar_subarrays(arr, n):
    count = defaultdict(int)  # 存储子数组频率的出现次数
    max_len = 0
    
    # 遍历所有的子数组 [l, r]
    for l in range(n):
        freq = [0] * (n + 1)  # 用于统计子数组元素出现次数
        for r in range(l, n):
            freq[arr[r]] += 1
            # 转化为不可变的 tuple 作为哈希的 key
            freq_tuple = tuple(freq)
            count[freq_tuple] += 1
            
            if count[freq_tuple] > 1:
                max_len = max(max_len, r - l + 1)
    
    return max_len

# 主函数
def solve():
    # 输入处理
    n, q = map(int, input().split())
    arr = list(map(int, input().split()))

    for _ in range(q):
        operation = input().split()

        if operation[0] == '1':  # 修改操作
            x = int(operation[1]) - 1
            y = int(operation[2])
            arr[x] = y  # 更新数组中第x个数字为y

        elif operation[0] == '2':  # 查询操作
            max_len = get_similar_subarrays(arr, n)
            print(max_len)  # print 默认会自动换行

# 执行函数
solve()

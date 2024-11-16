MOD = 10**9 + 7

# 使用Kadane算法计算数组中最大连续子数组的和，并返回其和、起始位置和结束位置
def max_subarray_sum(arr):
    max_sum = current_sum = 0  # 允许返回空子数组的和0
    start = end = s = 0

    for i, num in enumerate(arr):
        if current_sum + num > num:
            current_sum += num
        else:
            current_sum = num
            s = i
        
        if current_sum > max_sum:
            max_sum = current_sum
            start, end = s, i

    return max_sum, start, end  # 返回最大子数组和以及其起始和结束位置

def solve():
    T = int(input())  # 读取组数
    results = []

    for _ in range(T):
        n, k = map(int, input().split())  # 读取n和k
        arr = list(map(int, input().split()))  # 读取数组

        # 初始数组和
        total_sum = sum(arr)
        print(f"初始数组: {arr}, 总和: {total_sum}")

        # 每次插入最大子数组和，并更新数组
        for i in range(k):
            max_sub_sum, start, end = max_subarray_sum(arr)
            print(f"第{i+1}次操作: 最大子数组和 = {max_sub_sum}, start = {start}, end = {end}")
            
            # 将最大子数组和插入到最大子数组的中间
            insert_pos = (start + end) // 2  # 插入位置选择在中间
            arr.insert(insert_pos + 1, max_sub_sum)
            
            # 更新数组总和
            total_sum += max_sub_sum
            total_sum %= MOD
            print(f"操作后总和: {total_sum}, 更新后的数组: {arr}")

        # 确保结果为非负
        total_sum = (total_sum + MOD) % MOD

        # 记录结果
        results.append(total_sum)

    # 输出结果
    for result in results:
        print(result)

# 执行函数
solve()

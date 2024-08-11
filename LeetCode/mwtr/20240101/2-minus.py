# 小美有一个数组“，她想把这个数组求和，即a +a2 +a3 +......+ an 。
# 现在，她想把其中一个加号变成减号，但小美是小学生，不会负数的加减法，因此计算过程中不能出现负数。
# 小美想知道改变符号后答案的最小值是多少，如果不能改变符号，则输出-1。
# 输入描述：
# 第一行输入一个整n(1 <n < 105) 表示数组长度
# 第二行输入n 个整数表示数组a(1 < ai 10)
# 输出描述：
# 输出改变符号后的答案，若无法改变，则输出-1。

# 输入：
# 3 
# 3 2 1
# 输出：
# 2
# 解释：3+2-1=4,3-2+1=2；

n = int(input())
nums = list(map(int, input().split()))

# 如果数组中只有一个数，无法改变符号
if n == 1:
    print(-1)
else:
    # 计算数组的和
    total_sum = sum(nums)

    # 初始化最小值为无穷大
    min_sum = float('inf')

    # 遍历数组，尝试将每一个数作为被减数
    for i in range(1,n):
        # 计算改变符号后的答案
        new_sum = total_sum - 2 * nums[i]

        # 如果答案大于等于0，并且小于当前最小值，则更新最小值
        if new_sum >= 0 and new_sum < min_sum:
            min_sum = new_sum

    # 如果没有找到合适的改变符号的方式，则输出-1
    if min_sum == float('inf'):
        print(-1)
    else:
        print(min_sum)
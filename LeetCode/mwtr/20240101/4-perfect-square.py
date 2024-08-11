# 小美拿到了一个数组。她有若干次询问，每次询问 [l,r] 区间内第一个乘以x不是完全平方数的元素是什么。你能帮帮她吗?
# 输入描述：
# 第一行输入两个正整数n,q，代表数组大小和查询次数
# 第二行输入n个正整数ai，代表数组的元素。
# 接下来的q行，每行输入三个正整数l,r,z，代表一次询问。
# 1 < n,q,ai < 10^5
# 1<I<r<n
# 输出描述:
# 输出q行，每行输出一个答案。
# 如果区间内所有元素乘以x都是完全平方数，则输出-1。
# 否则输出一个正整数，代表区间最左边的乘以x不是完全平方数的元素。
# 例1
# 输入：
# 5 3
# 1 6 24 12 3
# 1 3 4
# 3 5 2
# 4 5 3
# 输出：
# 6
# 24
# -1
# 说明：
# [1,2]区间，第一个乘以 4 不是完全平方数的是第 2 个元素: 6。
# [3,5]区间，第一个乘以 2 不是完全平方数的是第 3 个元素: 24。
# [4,5]区间，不存在乘以 3 不是完全平方数的元素。

import math

def is_perfect_square(n):
    return int(math.sqrt(n))**2 == n

n, q = map(int, input().split())
arr = list(map(int, input().split()))

for _ in range(q):
    l, r, z = map(int, input().split())
    for i in range(l-1, r):
        if not is_perfect_square(arr[i] * z):
            print(arr[i])
            break
    else:
        print(-1)
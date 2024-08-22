# 小红拿到一个正整数x，她希望在[l,r]中选一个正整数y,满足x*y是完全平方数。小红想知道有多少种选择方案。
# 共有q次询问
# 输入
# 2
# 2 6 9
# 6 6 36
# 输出
# 1
# 2

# 输入第一行，q
# 接下来q行，每行3个正整数x,l,r
# 输出q行，每行一个整数是答案

# 说明：
# 对于第一组测试数据，只有选择8这个方案，2*8=16=4^2
# 第二组：选择6,24都合法

import math

def is_perfect_square(n):
    if n < 0:
        return False
    sqrt_n = int(math.isqrt(n))
    return sqrt_n * sqrt_n == n

def count_perfect_square_multiples(x, l, r):
    count = 0
    for y in range(l, r + 1):
        if is_perfect_square(x * y):
            count += 1
    return count

def solve(q, queries):
    results = []
    for i in range(q):
        x, l, r = queries[i]
        results.append(count_perfect_square_multiples(x, l, r))
    return results

q = int(input()) 
queries = [] 
for _ in range(q):     
    x, l, r = map(int, input().split())     
    queries.append((x, l, r))  

results = solve(q, queries)  
for result in results:     
    print(result)
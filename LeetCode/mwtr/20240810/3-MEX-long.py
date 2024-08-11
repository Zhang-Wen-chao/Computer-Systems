# 小美有一个长度为n的数组a1,a2,……an,他可以对数组进行如下操作：
# 删除第一个元素，a1,同时数组的长度简一，花费为x
# 删除整个数组，花费为k*MEX(a)（其中MEX（a)表示a中从未出现过的最小非负数，例如[0,1,2,4]的MEX为3
# 小美想知道将a数组全部清空的最小代价是多少。
# 输入：
# 1
# 6 3 3
# 4 5 2 3 1 0
# 输出
# 15
# 输入第一行是1组数据，第二行是n,k,x，分别代表了数组的元素数量、删除这个数组的花费系数，删除单个元素的花费。
# 输出是多种方法中的最小花费：先删除4，然后剩下的MEX[5 2 3 1 0]=4，花费3+4*3=15

# https://www.nowcoder.com/discuss/651750873652092928?sourceSSR=search

def find_min_cost(n, k, x, arr):
    def calculate_mex(arr):
        mex = 0
        while mex in arr:
            mex += 1
        return mex

    mex_value = calculate_mex(arr)
    min_cost = k * mex_value + x

    current_cost = 0
    for i in range(n):
        current_cost += x
        remaining_mex = calculate_mex(arr[i+1:])
        total_cost = current_cost + k * remaining_mex
        min_cost = min(min_cost, total_cost)

    return min_cost
n = 6
k = 3
x = 3
arr = [4, 5, 2, 3, 1, 0]

print(find_min_cost(n, k, x, arr)) # 15


# t = int(input())
# results = []

# for _ in range(t):
#     n, k, x = map(int, input().split())
#     arr = list(map(int, input().split()))
#     results.append(find_min_cost(n, k, x, arr))
# for result in results:
#     print(result)



# 下面这个代码是 acm 金牌写的。
# 第三题应该需要开long，没开long我也是过了案例0%，开了long直接ac了
# 作者：春秋招笔试突围
# 链接：https://www.nowcoder.com/discuss/651793815589695488?sourceSSR=users
# 来源：牛客网
# import heapq
# from collections import defaultdict

# def solve():
#     n, k, x = map(int, input().split())
#     a = list(map(int, input().split()))
#     count = defaultdict(int)
    
#     # 统计每个元素的出现次数
#     for num in a:
#         count[num] += 1
    
#     # 优先队列用于计算 MEX
#     mex_candidates = []
#     for i in range(n + 1):
#         if i not in count:
#             heapq.heappush(mex_candidates, i)
    
#     # 初始化最小花费
#     min_cost = heapq.heappop(mex_candidates) * k
#     heapq.heappush(mex_candidates, min_cost // k)
    
#     current_cost = 0
#     for num in a:
#         count[num] -= 1
#         if count[num] == 0:
#             heapq.heappush(mex_candidates, num)
        
#         current_cost += x
#         min_cost = min(min_cost, heapq.heappop(mex_candidates) * k + current_cost)
#         heapq.heappush(mex_candidates, min_cost // k)
    
#     print(min_cost)

# def main():
#     T = int(input())
#     for _ in range(T):
#         solve()

# if __name__ == "__main__":
#     main()
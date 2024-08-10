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
# n = 6
# k = 3
# x = 3
# arr = [4, 5, 2, 3, 1, 0]

# print(find_min_cost(n, k, x, arr)) # 15


t = int(input())
results = []

for _ in range(t):
    n, k, x = map(int, input().split())
    arr = list(map(int, input().split()))
    results.append(find_min_cost(n, k, x, arr))
for result in results:
    print(result)

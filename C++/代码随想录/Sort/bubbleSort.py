def bubble_sort(arr):
    n = len(arr)
    # 遍历所有数组元素
    for i in range(n):
        # 最后i个元素已经到位
        for j in range(0, n-i-1):
            # 遍历数组从0到n-i-1
            # 交换如果元素大于下一个元素
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

# 测试用例
test_cases = [
    [64, 34, 25, 12, 22, 11, 90],
    [5, 1, 4, 2, 8],
    [3, 0, 2, 5, -1, 4, 1],
    [7, 6, 5, 4, 3, 2, 1],
    [],
    [1],
    [1, 2, 3, 4, 5]
]

for arr in test_cases:
    print(f"Original Array: {arr}")
    print(f"Sorted Array: {bubble_sort(arr)}\n")

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2  # 找到中间位置
        L = arr[:mid]  # 分割数组的左半部分
        R = arr[mid:]  # 分割数组的右半部分

        merge_sort(L)  # 对左半部分进行排序
        merge_sort(R)  # 对右半部分进行排序

        i = j = k = 0

        # 将数据从两个临时数组复制回原数组arr
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        # 检查是否有剩余元素
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

    return arr

# 测试用例
test_cases = [
    [12, 11, 13, 5, 6, 7],
    [3, 2, 1],
    [9, 8, 7, 2, 3, 1],
    [],
    [1],
    [1, 2, 3, 4, 5]
]

for arr in test_cases:
    print(f"Original Array: {arr}")
    print(f"Sorted Array: {merge_sort(arr)}\n")

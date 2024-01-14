def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2  # 找到中间位置
        L = arr[:mid]  # 分割数组的左半部分
        R = arr[mid:]  # 分割数组的右半部分

        merge_sort(L)  # 对左半部分递归排序
        merge_sort(R)  # 对右半部分递归排序

        i = j = k = 0

        # 将数据从两个临时数组复制回原数组
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

# 测试用例
arr = [12, 11, 13, 5, 6, 7]
merge_sort(arr)
print("排序后的数组:", arr)

import bisect

def extract_median(n, arr):
    result = []
    arr.sort()
    
    for _ in range(n):
        length = len(arr)
        if length % 2 == 1:  # 奇数长度，取中间那个数
            median_index = length // 2
        else:  # 偶数长度，取中间两个数的较小值
            median_index = length // 2 - 1
        
        median = arr[median_index]
        result.append(median)
        
        # 使用二分查找移除中位数
        arr.pop(median_index)
    
    return result

# 读取输入
n = int(input())
arr = list(map(int, input().split()))

# 计算并输出结果
medians = extract_median(n, arr)
print(' '.join(map(str, medians)))

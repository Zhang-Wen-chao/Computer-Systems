import heapq
from collections import Counter

def topKFrequent(nums, k):
    # 使用 Counter 来统计每个元素的频率
    count = Counter(nums)
    
    # 使用堆（heap）来找出频率最高的 k 个元素
    return heapq.nlargest(k, count.keys(), key=count.get)

# 测试用例
print(topKFrequent([1,1,1,2,2,3], 2))  # 输出: [1, 2]
print(topKFrequent([1], 1))  # 输出: [1]

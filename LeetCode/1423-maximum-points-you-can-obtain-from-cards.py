from typing import List

def maxScore(cardPoints: List[int], k: int) -> int:
    # 计算总和
    total = sum(cardPoints)
    
    # 计算需要留下的卡牌数量
    n = len(cardPoints)
    leave_count = n - k
    
    # 特殊情况处理：如果需要拿的卡牌数等于卡牌总数
    if leave_count == 0:
        return total
    
    # 使用滑动窗口计算最小的子数组和
    min_subarray_sum = float('inf')
    current_sum = sum(cardPoints[:leave_count])
    min_subarray_sum = min(min_subarray_sum, current_sum)
    
    for i in range(leave_count, n):
        current_sum += cardPoints[i] - cardPoints[i - leave_count]
        min_subarray_sum = min(min_subarray_sum, current_sum)
    
    # 最大得分为总和减去最小的子数组和
    return total - min_subarray_sum

# 示例
cardPoints = [1, 2, 3, 4, 5, 6, 1]
k = 3
result = maxScore(cardPoints, k)
print(result)  # 输出应该是12

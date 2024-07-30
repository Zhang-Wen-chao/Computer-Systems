from heapq import heappop, heappush
from collections import Counter

def reorganizeString(s: str) -> str:
    # 统计每个字符的出现频率
    freq = Counter(s)
    
    # 用最大堆存储字符和它们的频率（负数，因为Python默认最小堆）
    max_heap = []
    for char, count in freq.items():
        heappush(max_heap, (-count, char))
    
    # 结果字符串
    result = []
    
    # 上一个取出的字符
    prev_count, prev_char = 0, ''
    
    while max_heap:
        count, char = heappop(max_heap)
        
        # 把上一个字符重新放回堆中
        if prev_count < 0:
            heappush(max_heap, (prev_count, prev_char))
        
        # 添加当前字符到结果字符串
        result.append(char)
        
        # 更新上一个字符和它的频率
        prev_count, prev_char = count + 1, char
    
    result_str = ''.join(result)
    
    # 检查结果字符串长度是否等于原字符串长度
    if len(result_str) != len(s):
        return ""
    
    return result_str

# 示例
s = "aab"
print("原始字符串:", s)
print("重构后的字符串:", reorganizeString(s))

print('*' * 50)

s = "aaab"
print("原始字符串:", s)
print("重构后的字符串:", reorganizeString(s))

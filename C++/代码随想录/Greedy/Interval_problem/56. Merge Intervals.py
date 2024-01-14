def merge(intervals):
    if not intervals:
        return []

    # 根据每个区间的起始位置进行排序
    intervals.sort(key=lambda x: x[0])

    merged = [intervals[0]]
    for interval in intervals[1:]:
        # 如果当前区间的起始位置小于等于已合并区间的结束位置，则合并
        if interval[0] <= merged[-1][1]:
            merged[-1][1] = max(merged[-1][1], interval[1])
        else:
            merged.append(interval)

    return merged

# 测试用例
print(merge([[1,3],[2,6],[8,10],[15,18]]))  # 应该输出 [[1,6],[8,10],[15,18]]
print(merge([[1,4],[4,5]]))                # 应该输出 [[1,5]]

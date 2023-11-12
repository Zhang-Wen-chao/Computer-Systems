def eraseOverlapIntervals(intervals):
    if not intervals:
        return 0

    # 根据每个区间的结束时间对区间进行排序
    intervals.sort(key=lambda x: x[1])

    # 初始化
    end = intervals[0][1]
    count = 0

    for i in range(1, len(intervals)):
        # 如果当前区间的开始时间小于上一个区间的结束时间
        if intervals[i][0] < end:
            # 需要移除一个区间
            count += 1
        else:
            # 更新结束时间
            end = intervals[i][1]

    return count

# 测试用例
print(eraseOverlapIntervals([[1,2],[2,3],[3,4],[1,3]]))  # 应该输出 1
print(eraseOverlapIntervals([[1,2],[1,2],[1,2]]))        # 应该输出 2
print(eraseOverlapIntervals([[1,2],[2,3]]))              # 应该输出 0

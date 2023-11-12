import heapq

def minMeetingRooms(intervals):
    if not intervals:
        return 0

    # 根据会议的开始时间对会议进行排序
    intervals.sort(key=lambda x: x[0])

    # 创建一个最小堆来跟踪最早结束的会议
    heap = []

    # 将第一个会议的结束时间加入堆中
    heapq.heappush(heap, intervals[0][1])

    for i in intervals[1:]:
        # 如果当前会议的开始时间大于或等于堆顶会议的结束时间
        if i[0] >= heap[0]:
            # 移除堆顶元素（结束最早的会议）
            heapq.heappop(heap)
        # 将当前会议的结束时间加入堆中
        heapq.heappush(heap, i[1])

    # 堆的大小就是所需的会议室数量
    return len(heap)

# 测试用例
print(minMeetingRooms([[0, 30],[5, 10],[15, 20]]))  # 应该输出 2
print(minMeetingRooms([[7,10],[2,4]]))             # 应该输出 1

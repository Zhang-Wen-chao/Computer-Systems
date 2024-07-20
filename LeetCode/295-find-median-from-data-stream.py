import heapq

class MedianFinder:

    def __init__(self):
        # 最大堆，存储较小的一半数字
        self.small = []
        # 最小堆，存储较大的一半数字
        self.large = []
        

    def addNum(self, num: int) -> None:
        # 为了模拟最大堆，我们将数字的负值存储到self.small中
        heapq.heappush(self.small, -num)
        # 将最大堆的最大值（即负值的最小值）放入最小堆中
        heapq.heappush(self.large, -heapq.heappop(self.small))
        
        # 如果最小堆的长度超过最大堆的长度，我们将最小堆的最小值放入最大堆中
        if len(self.large) > len(self.small):
            heapq.heappush(self.small, -heapq.heappop(self.large))

    def findMedian(self) -> float:
        # 如果两个堆的长度相等，说明总数为偶数，中位数为两个堆顶的平均值
        if len(self.small) == len(self.large):
            return (-self.small[0] + self.large[0]) / 2.0
        # 否则，中位数为最大堆的堆顶
        else:
            return -self.small[0]

# 示例用法：
operations = ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
values = [[], [1], [2], [], [3], []]

obj = None
results = []

for op, val in zip(operations, values):
    if op == "MedianFinder":
        obj = MedianFinder()
        results.append(None)
    elif op == "addNum":
        obj.addNum(val[0])
        results.append(None)
    elif op == "findMedian":
        median = obj.findMedian()
        results.append(median)

print(results)  # 输出 [None, None, None, 1.5, None, 2.0]

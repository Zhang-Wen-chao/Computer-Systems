# 我们正在为一个日程安排管理系统开发一个关键功能。在这个系统中，有两个不同的用户群体，分别有他们各自的空闲日程区间列表。
# 第一个用户群体的空闲日程区间列表记为firstList,其中 firstList[il= [start_i, end_i];同样地，第二个用户群体的日程区间列表记
# 为 secondList , secondList[j] = [start_j, end_j].
# 每个用户群体的日程区间都是成对出现且不相交的，并且两个列表都已经按照时间顺序排好序。
# 现在，为了找到两个用户群体都有空闲时间可以进行共同活动的时间段，需要设计一个算法来返回这两个日程区间列表的交集，将其找出来以便系统可以安排共同的活动。
# 请你设计一个高效的算法来解决这个问题。
# 补充说明
# 输入中的每个日程区间为:[start_i, end_i]
# def findintersection（self，firstList，secondList）->List
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param firstList int整型二维数组 
# @param secondList int整型二维数组 
# @return int整型二维数组
#
class Solution:
    def findIntersection(self , firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        # write code here
        result = []
        i, j = 0, 0
        while i < len(firstList) and j < len(secondList):
            start_i, end_i = firstList[i]
            start_j, end_j = secondList[j]
            start_overlap = max(start_i, start_j)
            end_overlap = min(end_i, end_j)
            if start_overlap <= end_overlap:
                result.append([start_overlap,end_overlap])
            
            if end_i < end_j:
                i += 1
            else:
                j += 1
        return result
// 253.meeting-rooms-ii
// https://leetcode.com/problems/meeting-rooms-ii/
// Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

int minMeetingRooms(std::vector<Interval>& intervals) {
    // 按照会议开始时间进行升序排序
    std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        return a.start < b.start;
    });

    // 使用最小堆来存储会议室的结束时间
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // 将第一个会议的结束时间加入最小堆
    minHeap.push(intervals[0].end);

    // 遍历剩余的会议时间段
    for (int i = 1; i < intervals.size(); ++i) {
        // 如果当前会议的开始时间晚于最早结束的会议时间，说明可以复用同一个会议室
        if (intervals[i].start >= minHeap.top()) {
            minHeap.pop();
        }

        // 将当前会议的结束时间加入最小堆
        minHeap.push(intervals[i].end);
    }

    // 最小堆中的元素个数即为需要的会议室数量
    return minHeap.size();
}

int main() {
    std::vector<Interval> intervals = {{0, 30}, {5, 10}, {15, 20}};
    std::cout << "Minimum meeting rooms required: " << minMeetingRooms(intervals) << std::endl;

    std::vector<Interval> intervals2 = {{7, 10}, {2, 4}};
    std::cout << "Minimum meeting rooms required: " << minMeetingRooms(intervals2) << std::endl;

    std::vector<Interval> intervals3 = {{1, 5}, {8, 9}, {8, 9}};
    std::cout << "Minimum meeting rooms required: " << minMeetingRooms(intervals3) << std::endl;
    
    return 0;
}

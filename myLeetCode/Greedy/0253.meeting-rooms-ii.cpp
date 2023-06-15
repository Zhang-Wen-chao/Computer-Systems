// 253.meeting-rooms-ii
// https://leetcode.com/problems/meeting-rooms-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

int minMeetingRooms(vector<Interval>& intervals) {
    // 按照会议开始时间排序
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        return a.start < b.start;
    });

    // 创建一个小根堆，存储每个会议的结束时间
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto& interval : intervals) {
        // 如果当前会议开始时间晚于最早结束的会议时间，那么将这个会议室空出来，可以被当前会议使用
        if (!pq.empty() && pq.top() <= interval.start) {
            pq.pop();
        }
        // 把当前会议的结束时间加入小根堆中
        pq.push(interval.end);
    }

    // 最终小根堆中的元素个数就是需要的最少的会议室数量
    return pq.size();
}

int main() {
    int n;
    cin >> n;
    vector<Interval> intervals;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        intervals.push_back(Interval(start, end));
    }
    int min_rooms = minMeetingRooms(intervals);
    cout << min_rooms << endl;
    return 0;
}
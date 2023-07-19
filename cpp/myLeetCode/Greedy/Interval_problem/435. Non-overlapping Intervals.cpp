// 435. Non-overlapping Intervals
// https://leetcode.com/problems/non-overlapping-intervals/

#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.start < b.start;
}

int eraseOverlapIntervals(std::vector<Interval>& intervals) {
    if (intervals.empty()) {
        return 0;
    }

    std::sort(intervals.begin(), intervals.end(), compareIntervals);

    int count = 0;
    int prevEnd = intervals[0].end;

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].start < prevEnd) {
            count++;
            prevEnd = std::min(prevEnd, intervals[i].end);
        } else {
            prevEnd = intervals[i].end;
        }
    }

    return count;
}

int main() {
    std::vector<Interval> intervals{{1,2}, {2,3}, {3,4}, {1,3}};
    std::cout << "Minimum number of intervals to remove: " << eraseOverlapIntervals(intervals) << std::endl;

    std::vector<Interval> intervals2{{1,2}, {1,2}, {1,2}};
    std::cout << "Minimum number of intervals to remove: " << eraseOverlapIntervals(intervals2) << std::endl;

    std::vector<Interval> intervals3{{1,2}, {2,3}};
    std::cout << "Minimum number of intervals to remove: " << eraseOverlapIntervals(intervals3) << std::endl;

    return 0;
}


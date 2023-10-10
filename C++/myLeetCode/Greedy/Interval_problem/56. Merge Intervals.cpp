// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/

#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compareIntervals(Interval& a, Interval& b) {
    return a.start < b.start;
}

std::vector<Interval> mergeIntervals(std::vector<Interval>& intervals) {
    std::vector<Interval> mergedIntervals;
    if (intervals.empty()) {
        return mergedIntervals;
    }

    // 按照区间的起始位置进行排序
    std::sort(intervals.begin(), intervals.end(), compareIntervals);

    // 将第一个区间加入结果列表作为初始状态
    mergedIntervals.push_back(intervals[0]);

    // 遍历剩余的区间
    for (int i = 1; i < intervals.size(); i++) {
        Interval& current = intervals[i];
        Interval& previous = mergedIntervals.back();

        // 如果当前区间的起始位置在前一个合并区间的范围内，更新合并区间的结束位置
        if (current.start <= previous.end) {
            previous.end = std::max(previous.end, current.end);
        } else {
            // 否则，将当前区间添加到合并区间列表中
            mergedIntervals.push_back(current);
        }
    }

    return mergedIntervals;
}

int main() {
    std::vector<Interval> input = {Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)};
    std::cout << "Merge Intervals: ";
    for (Interval& interval : mergeIntervals(input)) {
        std::cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    std::cout << std::endl;

    std::vector<Interval> input2 = {Interval(1, 4), Interval(4, 5)};
    std::cout << "Merge Intervals: ";
    for (Interval& interval : mergeIntervals(input2)) {
        std::cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    std::cout << std::endl;

    return 0;
}
// 435. Non-overlapping Intervals
// https://leetcode.com/problems/non-overlapping-intervals/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A struct to represent an interval
struct Interval {
    int start;
    int end;
};

// A comparator function to sort intervals by their end time
bool cmp(Interval a, Interval b) {
    return a.end < b.end;
}

// A function to find the minimum number of intervals to remove
int eraseOverlapIntervals(vector<Interval>& intervals) {
    int count = 0;
    if (intervals.empty()) return count;

    sort(intervals.begin(), intervals.end(), cmp);

    int prev_end = intervals[0].end;
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].start < prev_end) {
            count++;
        } else {
            prev_end = intervals[i].end;
        }
    }

    return count;
}

int main() {
    vector<Interval> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};
    cout << "Minimum number of intervals to remove: " << eraseOverlapIntervals(intervals) << endl;
    return 0;
}

// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start, end;
};

bool cmp(Interval a, Interval b) {
    return a.start < b.start;
}

vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> res;
    if (intervals.empty()) return res;
    sort(intervals.begin(), intervals.end(), cmp);
    Interval cur = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
        if (cur.end >= intervals[i].start) cur.end = max(cur.end, intervals[i].end);
        else {
            res.push_back(cur);
            cur = intervals[i];
        }
    }
    res.push_back(cur);
    return res;
}

int main() {
    vector<Interval> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    cout << "The merged intervals are: ";
    for (Interval x : merge(intervals)) {
        cout << "[" << x.start << "," << x.end << "] ";
    }
    cout << endl;
    return 0;
}


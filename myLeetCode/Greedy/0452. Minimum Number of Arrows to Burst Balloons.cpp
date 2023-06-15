// 452. Minimum Number of Arrows to Burst Balloons
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), cmp);
    int arrows = 0, end = INT_MIN;
    for (auto& p : points) {
        if (p[0] > end) {
            end = p[1];
            arrows++;
        }
    }
    return arrows;
}

int main() {
    vector<vector<int>> points = {{10,16}, {2,8}, {1,6}, {7,12}};
    cout << findMinArrowShots(points) << endl; // Output: 2
}

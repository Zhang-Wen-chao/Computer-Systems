// 452. Minimum Number of Arrows to Burst Balloons
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(const std::vector<int>& a, const std::vector<int>& b) {
    return a[1] < b[1];
}

int findMinArrowShots(std::vector<std::vector<int>>& points) {
    if (points.empty()) {
        return 0;
    }

    std::sort(points.begin(), points.end(), cmp);

    int arrows = 1;
    int end = points[0][1];

    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > end) {
            arrows++;
            end = points[i][1];
        }
    }

    return arrows;
}

int main() {
    std::vector<std::vector<int>> points{{10,16},{2,8},{1,6},{7,12}};
    std::cout << "Minimum number of arrows to burst balloons: " << findMinArrowShots(points) << std::endl;

    std::vector<std::vector<int>> points2{{1,2},{3,4},{5,6},{7,8}};
    std::cout << "Minimum number of arrows to burst balloons: " << findMinArrowShots(points2) << std::endl;

    std::vector<std::vector<int>> points3{{1,2},{2,3},{3,4},{4,5}};
    std::cout << "Minimum number of arrows to burst balloons: " << findMinArrowShots(points3) << std::endl;
    
    return 0;
}

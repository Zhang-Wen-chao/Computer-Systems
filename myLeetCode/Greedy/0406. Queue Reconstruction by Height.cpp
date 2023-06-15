// 406. Queue Reconstruction by Height
// https://leetcode.com/problems/queue-reconstruction-by-height/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    });

    vector<vector<int>> ans;
    for (const vector<int>& p : people) {
        ans.insert(ans.begin() + p[1], p);
    }

    return ans;
}

int main() {
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> output = {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};

    cout << "Input: people = ";
    for (const vector<int>& p : people) {
        cout << "[" << p[0] << "," << p[1] << "],";
    }
    cout << endl;

    cout << "Output: ";
    for (const vector<int>& q : reconstructQueue(people)) {
        cout << "[" << q[0] << "," << q[1] << "],";
    }
    cout << endl;

    return 0;
}

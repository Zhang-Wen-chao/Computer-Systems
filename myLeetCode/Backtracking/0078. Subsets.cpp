// 78. Subsets
// https://leetcode.com/problems/subsets/
#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, int start) {
    res.push_back(path);
    for (int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtrack(res, path, nums, i+1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    backtrack(res, path, nums, 0);
    return res;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = subsets(nums);
    cout << "Input: [";
    for (int i = 0; i < nums.size()-1; i++) {
        cout << nums[i] << ", ";
    }
    cout << nums[nums.size()-1] << "]" << endl;
    cout << "Output: [";
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size()-1; j++) {
            cout << res[i][j] << ", ";
        }
        if (!res[i].empty()) {
            cout << res[i][res[i].size()-1];
        }
        cout << "]";
        if (i < res.size()-1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}


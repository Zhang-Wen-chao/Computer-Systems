// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<vector<int>>& res, vector<int>& candidates, vector<int>& path, int target, int start) {
    if (target < 0) return;
    if (target == 0) {
        res.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        path.push_back(candidates[i]);
        backtrack(res, candidates, path, target-candidates[i], i);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    backtrack(res, candidates, path, target, 0);
    return res;
}

int main() {
    vector<int> candidates = {2,3,5,8};
    int target = 8;
    vector<vector<int>> res = combinationSum(candidates, target);
    cout << "Input: " << target << " [" << candidates[0];
    for (int i = 1; i < candidates.size(); i++) {
        cout << ", " << candidates[i];
    }
    cout << "]" << endl;
    cout << "Output: " << endl;
    for (vector<int> path : res) {
        cout << "[";
        for (int i = 0; i < path.size()-1; i++) {
            cout << path[i] << ", ";
        }
        cout << path[path.size()-1] << "]" << endl;
    }
    return 0;
}

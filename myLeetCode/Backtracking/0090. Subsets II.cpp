// LeetCode 90. Subsets II
// https://leetcode.com/problems/subsets-ii/
// Author: GoodTecher
// Date: 2021-10-30

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> subset;
        
        // sort the nums to make sure the duplicates are adjacent
        sort(nums.begin(), nums.end());
        
        // backtrack to find all subsets
        backtrack(nums, 0, subset, results);
        
        return results;
    }
    
private:
    void backtrack(vector<int>& nums, int startIndex, vector<int>& subset, vector<vector<int>>& results) {
        // add the current subset to the results
        results.push_back(subset);
        
        for (int i = startIndex; i < nums.size(); i++) {
            // skip the duplicates
            if (i > startIndex && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // choose the current number and add it to the subset
            subset.push_back(nums[i]);
            
            // backtrack with the next index
            backtrack(nums, i + 1, subset, results);
            
            // undo the choice and remove the last number from the subset
            subset.pop_back();
        }
    }
};

int main() {
    // test case: nums = [1, 2, 2]
    vector<int> nums = {1, 2, 2};
    
    Solution solution;
    vector<vector<int>> results = solution.subsetsWithDup(nums);
    
    // print the output: [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]
    cout << "[";
    for (int i = 0; i < results.size(); i++) {
        cout << "[";
        for (int j = 0; j < results[i].size(); j++) {
            cout << results[i][j];
            if (j < results[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < results.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    return 0;
}
// 376. Wiggle Subsequence
// https://leetcode.com/problems/wiggle-subsequence/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // 当前一对差值
        int preDiff = 0; // 前一对差值
        int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            // 出现峰值
            if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};


int main() {
  
  vector<int> input1 = {1,7,4,9,2,5}; // Expected output:6 
  vector<int> input2 = {1,17,5,10,13,15,10,5,16,8}; // Expected output:7 
  vector<int> input3 = {1}; // Expected output:1 
  Solution sol;
  cout << "The length of longest wiggle subsequence for input1 is " << sol.wiggleMaxLength(input1) << endl;
  cout << "The length of longest wiggle subsequence for input2 is " << sol.wiggleMaxLength(input2) << endl;
  cout << "The length of longest wiggle subsequence for input3 is " << sol.wiggleMaxLength(input3) << endl;

   return 0;
}
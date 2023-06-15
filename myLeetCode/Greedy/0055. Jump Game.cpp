// 55. Jump Game
// https://leetcode.com/problems/jump-game/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true; // 只有一个元素，就是能达到
        for (int i = 0; i <= cover; i++) { // 注意这里是小于等于cover
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true; // 说明可以覆盖到终点了
        }
        return false;
    }
};

int main() {

  vector<int> input1 = {2,3,1,1,4}; // Expected output:true 
  vector<int> input2 = {3,2,1,0,4}; // Expected output:false 
  vector<int> input3 = {0}; // Expected output:true 
  Solution sol;
  cout << "The result for input1 is " << (sol.canJump(input1) ? "true" : "false") << endl;
  cout << "The result for input2 is " << (sol.canJump(input2) ? "true" : "false") << endl;
  cout << "The result for input3 is " << (sol.canJump(input3) ? "true" : "false") << endl;

  return 0;
}
// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArray(vector<int>& nums) {
  int currSum = 0;
  int maxSum = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    currSum += nums[i];
    maxSum = max(maxSum, currSum);

    if (currSum < 0) currSum = 0;
  }
  return maxSum;
}

int main() {

   vector<int> input1 = {-2,1,-3,4,-1,2,1,-5,4}; // Expected output:6 
   vector<int> input2 = {5,4,-1,7,8}; // Expected output:23 
   vector<int> input3 = {-1}; // Expected output:-1 

   cout << "The maximum subarray sum for input1 is " << maxSubArray(input1) << endl;
   cout << "The maximum subarray sum for input2 is " << maxSubArray(input2) << endl;
   cout << "The maximum subarray sum for input3 is " << maxSubArray(input3) << endl;

   return 0;
}
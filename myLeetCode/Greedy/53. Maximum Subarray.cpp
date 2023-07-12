// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <vector>
#include <algorithm>

int maxSubarraySum(const std::vector<int>& nums) {
    int currentMax = nums[0];
    int globalMax = nums[0];

    for (const auto& num : nums) {
        currentMax = std::max(num, currentMax + num);
        globalMax = std::max(globalMax, currentMax);
    }

    return globalMax;
}

int main() {
    
    vector<int> input1 = {-2,1,-3,4,-1,2,1,-5,4}; // Expected output:6 
    vector<int> input2 = {5,4,-1,7,8}; // Expected output:23 
    vector<int> input3 = {-1}; // Expected output:-1 

    cout << "The maximum subarray sum for input1 is " << maxSubArray(input1) << endl;
    cout << "The maximum subarray sum for input2 is " << maxSubArray(input2) << endl;
    cout << "The maximum subarray sum for input3 is " << maxSubArray(input3) << endl;

    return 0;
    // write a bubble sort
}
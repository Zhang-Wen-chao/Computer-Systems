// 1005. Maximize Sum Of Array After K Negations
// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

// * 第一步：将数组按照绝对值大小从大到小排序，**注意要按照绝对值的大小**
// * 第二步：从前向后遍历，遇到负数将其变为正数，同时K--
// * 第三步：如果K还大于0，那么反复转变数值最小的元素，将K用完
// * 第四步：求和
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
static bool cmp(int a, int b) {
    return abs(a) > abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);       // 第一步
        for (int i = 0; i < A.size(); i++) { // 第二步
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        if (K % 2 == 1) A[A.size() - 1] *= -1; // 第三步
        int result = 0;
        for (int a : A) result += a;        // 第四步
        return result;
    }
};

int main() {
    vector<int> nums1 = {4,2,3}; 
    int k1 = 1;
    Solution sol;
    cout << sol.largestSumAfterKNegations(nums1, k1) << endl;

    vector<int> nums2 = {3,-1,0,2}; 
    int k2 = 3;
    cout << sol.largestSumAfterKNegations(nums2, k2) << endl;

    vector<int> nums3 = {2,-3,-1,5,-4};
    int k3 = 2;
    cout << sol.largestSumAfterKNegations(nums3, k3) << endl;

    return 0;
}

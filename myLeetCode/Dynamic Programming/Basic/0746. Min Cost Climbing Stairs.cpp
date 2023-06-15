// LeetCode 746. Min Cost Climbing Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // get the size of the cost array
        int n = cost.size();
        
        // create an array to store the minimum cost to reach each step
        vector<int> dp(n + 1);
        
        // initialize the first two steps with zero cost
        dp[0] = 0;
        dp[1] = 0;
        
        // iterate from the third step to the top of the floor
        for (int i = 2; i <= n; i++) {
            // calculate the minimum cost to reach the current step by comparing the previous two steps
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        
        // return the minimum cost to reach the top of the floor
        return dp[n];
    }
};

int main() {
    // test case: cost = [10,15,20]
    // vector<int> cost = {10,15,20};
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    
    Solution solution;
    int result = solution.minCostClimbingStairs(cost);
    
    // print the output: 15
    cout << result << endl;
    
    return 0;
}

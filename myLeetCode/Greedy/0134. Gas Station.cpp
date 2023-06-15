// 134. Gas Station
// https://leetcode.com/problems/gas-station/

#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size(), total = 0, curr = 0, start = 0;
    for (int i = 0; i < n; i++) {
        total += gas[i] - cost[i];
        curr += gas[i] - cost[i];
        if (curr < 0) {
            curr = 0;
            start = i + 1;
        }
    }
    return (total >= 0) ? start : -1;
}

int main() {
    vector<int> gas1 = {1,2,3,4,5}, cost1 = {3,4,5,1,2}, gas2 = {2,3,4}, cost2 = {3,4,3};
    cout << canCompleteCircuit(gas1, cost1) << endl;
    cout << canCompleteCircuit(gas2, cost2) << endl;
    return 0;
}

// 134. Gas Station
// https://leetcode.com/problems/gas-station/

#include <iostream>
#include <vector>

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
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
    std::vector<int> gas1 = {1,2,3,4,5}, cost1 = {3,4,5,1,2}; // Expected output:3
    std::cout << canCompleteCircuit(gas1, cost1) << std::endl;

    std::vector<int> gas2 = {2,3,4}, cost2 = {3,4,3}; // Expected output:-1
    std::cout << canCompleteCircuit(gas2, cost2) << std::endl;
    
    return 0;
}

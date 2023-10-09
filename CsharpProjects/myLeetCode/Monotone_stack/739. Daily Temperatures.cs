// 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/

#include <iostream>
#include <vector>
#include <stack>

std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    int n = temperatures.size();
    std::vector<int> result(n, 0);
    std::stack<int> stk;

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
            int index = stk.top();
            stk.pop();
            result[index] = i - index;
        }
        stk.push(i);
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {73, 74, 75, 71, 69, 72, 76, 73},
        {30, 40, 50, 60},
        {30, 60, 90}
    };

    for (int i = 0; i < testCases.size(); i++) {
        std::vector<int> temperatures = testCases[i];

        std::vector<int> result = dailyTemperatures(temperatures);

        std::cout << "Number of days until a warmer temperature for test case " << (i + 1) << ": ";
        for (int j = 0; j < result.size(); j++) {
            std::cout << result[j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
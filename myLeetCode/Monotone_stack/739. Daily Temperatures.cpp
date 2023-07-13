// 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/

#include <iostream>
#include <vector>
#include <stack>

std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    int n = temperatures.size();
    std::vector<int> result(n, 0);
    std::stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int index = st.top();
            st.pop();
            result[index] = i - index;
        }
        st.push(i);
    }

    return result;
}

int main() {
    std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    std::vector<int> result = dailyTemperatures(temperatures);

    std::cout << "Number of days until a warmer temperature: ";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
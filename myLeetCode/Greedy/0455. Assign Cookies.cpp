// 455. Assign Cookies
// https://leetcode.com/problems/assign-cookies/

// 可以尝试使用贪心策略，先将饼干数组和小孩数组排序。
// 然后从后向前遍历小孩数组，用大饼干优先满足胃口大的，并统计满足小孩数量。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1; // 饼干数组的下标
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) {
            if (index >= 0 && s[index] >= g[i]) {
                result++;
                index--;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> g = {1,2}; // greed factors of children
    vector<int> s = {1,2,3}; // sizes of cookies
    int ans = sol.findContentChildren(g, s); // expected answer: 1
    cout << ans << endl;
    return 0;
}
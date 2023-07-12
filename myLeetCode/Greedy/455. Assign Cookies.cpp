// 455. Assign Cookies
// https://leetcode.com/problems/assign-cookies/

#include <iostream>
#include <vector>
#include <algorithm>

int findContentChildren(std::vector<int>& greed, std::vector<int>& cookies) {
    std::sort(greed.begin(), greed.end());
    std::sort(cookies.begin(), cookies.end());

    int greedIndex = 0;
    int cookieIndex = 0;
    int count = 0;

    while (greedIndex < greed.size() && cookieIndex < cookies.size()) {
        if (greed[greedIndex] <= cookies[cookieIndex]) {
            count++;
            greedIndex++;
        }
        cookieIndex++;
    }

return count;
}

int main() {
    std::vector<int> g = {1,2}; // greed factors of children
    std::vector<int> s = {1,2,3}; // sizes of cookies
    int ans = findContentChildren(g, s); // expected answer: 1
    std::cout << ans << std::endl;
    
    return 0;
}
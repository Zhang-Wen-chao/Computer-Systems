// 135. Candy
// https://leetcode.com/problems/candy/

#include <iostream>
#include <vector>
#include <numeric>

int candy(std::vector<int>& ratings) {
    int n = ratings.size();
    std::vector<int> candies(n, 1);
    
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = std::max(candies[i], candies[i + 1] + 1);
        }
    }

    return std::accumulate(candies.begin(), candies.end(), 0);
}

int main() {
    std::vector<int> ratings = {1, 0, 2}; // Expected output:5
    std::cout << "Minimum number of candies: " << candy(ratings) << std::endl;

    std::vector<int> ratings2 = {1, 2, 2}; // Expected output:4
    std::cout << "Minimum number of candies: " << candy(ratings2) << std::endl;
    
    return 0;
}
// 135. Candy
// https://leetcode.com/problems/candy/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int candy(vector<int>& ratings) {
    vector<int> candyVec(ratings.size(), 1);
    // 从前向后
    for (int i = 1; i < ratings.size(); i++) {
        if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
    }
    // 从后向前
    for (int i = ratings.size() - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
        }
    }
    // 统计结果
    return accumulate(candyVec.begin(), candyVec.end(), 0);
}

int main() {
     vector<int> ratings = {1, 0, 2};
     int expected_output = 5;

     int actual_output = candy(ratings);

     cout << "Input: [";
     for (int r : ratings) {
          cout << r << ",";
     }
     cout << "]" << endl;
     cout << "Expected Output: " << expected_output << endl;
     cout << "Actual Output: " << actual_output << endl;
}

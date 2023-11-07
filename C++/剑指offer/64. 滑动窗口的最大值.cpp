#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // Stores indices
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        // Remove indices that are out of the current window
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Remove indices whose corresponding values are less than nums[i]
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // The front of the deque is the index of the largest value in the current window
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Max values in each sliding window: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

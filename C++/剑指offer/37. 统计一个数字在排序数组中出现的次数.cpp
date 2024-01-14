#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        int first = GetFirstK(data, k, 0, data.size() - 1);
        int last = GetLastK(data, k, 0, data.size() - 1);
        if (first == -1 || last == -1) return 0;
        return last - first + 1;
    }

private:
    int GetFirstK(const vector<int>& data, int k, int start, int end) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (data[mid] < k) {
                start = mid + 1;
            } else if (data[mid] > k) {
                end = mid - 1;
            } else {
                if ((mid > 0 && data[mid - 1] != k) || mid == 0) {
                    return mid;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }

    int GetLastK(const vector<int>& data, int k, int start, int end) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (data[mid] < k) {
                start = mid + 1;
            } else if (data[mid] > k) {
                end = mid - 1;
            } else {
                if ((mid < data.size() - 1 && data[mid + 1] != k) || mid == data.size() - 1) {
                    return mid;
                } else {
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> data = {1, 2, 3, 3, 3, 3, 4, 5};
    int k = 3;
    int count = solution.GetNumberOfK(data, k);
    cout << "Number " << k << " appears " << count << " times in the array." << endl;
    return 0;
}

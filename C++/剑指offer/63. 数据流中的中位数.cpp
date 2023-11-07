#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class MedianFinder {
    priority_queue<int, vector<int>, less<int>> maxHeap; // Max heap for the first half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for the second half

public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }
};

int main() {
    MedianFinder finder;

    // Simulate the data stream
    vector<int> dataStream = {2, 3, 4, 1, 5, 6, 7, 8, 9, 10};
    for (int num : dataStream) {
        finder.addNum(num);
        cout << "Current median: " << finder.findMedian() << endl;
    }

    return 0;
}

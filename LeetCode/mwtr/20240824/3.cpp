#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

long long maxProductAfterKOperations(long long a, long long b, long long c, long long k) {
    // Use a min-heap (priority queue) to efficiently get the minimum element
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    
    // Push all elements into the min-heap
    minHeap.push(a);
    minHeap.push(b);
    minHeap.push(c);
    
    // Perform k operations
    while (k > 0) {
        long long minElement = minHeap.top(); // Get the smallest element
        minHeap.pop(); // Remove the smallest element from the heap
        minHeap.push(minElement + 1); // Increment it and push it back into the heap
        k--;
    }
    
    // Calculate the product of the three elements
    long long result = 1;
    while (!minHeap.empty()) {
        result = result * (minHeap.top() % MOD) % MOD;
        minHeap.pop();
    }
    
    return result;
}

int main() {
    long long a, b, c, k;
    cin >> a >> b >> c >> k;
    cout << maxProductAfterKOperations(a, b, c, k) << endl;
    return 0;
}

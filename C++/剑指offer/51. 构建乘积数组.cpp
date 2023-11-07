#include <iostream>
#include <vector>

using namespace std;

vector<int> constructProductArray(const vector<int>& input) {
    int n = input.size();
    vector<int> B(n, 1); // Initialize B with 1s

    // Calculate the products below the current index
    for (int i = 1; i < n; ++i) {
        B[i] = B[i - 1] * input[i - 1];
    }

    // Calculate the products above the current index
    int temp = 1;
    for (int i = n - 2; i >= 0; --i) {
        temp *= input[i + 1];
        B[i] *= temp;
    }

    return B;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = constructProductArray(A);

    cout << "The product array is: ";
    for (int num : B) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

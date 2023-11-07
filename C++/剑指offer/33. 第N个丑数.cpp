#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetUglyNumber(int index) {
    if (index <= 0) return 0;
    vector<int> uglyNumbers(index);
    uglyNumbers[0] = 1;
    int nextUglyIndex = 1;

    vector<int>::iterator multiply2 = uglyNumbers.begin();
    vector<int>::iterator multiply3 = uglyNumbers.begin();
    vector<int>::iterator multiply5 = uglyNumbers.begin();

    while (nextUglyIndex < index) {
        int minVal = min({*multiply2 * 2, *multiply3 * 3, *multiply5 * 5});
        uglyNumbers[nextUglyIndex] = minVal;

        while (*multiply2 * 2 <= uglyNumbers[nextUglyIndex])
            ++multiply2;
        while (*multiply3 * 3 <= uglyNumbers[nextUglyIndex])
            ++multiply3;
        while (*multiply5 * 5 <= uglyNumbers[nextUglyIndex])
            ++multiply5;

        ++nextUglyIndex;
    }

    return uglyNumbers[index - 1];
}

int main() {
    int n;
    cout << "Enter the index of the ugly number you want to find: ";
    cin >> n;
    int uglyNumber = GetUglyNumber(n);
    cout << "The " << n << "th ugly number is: " << uglyNumber << endl;
    return 0;
}

// 738. Monotone Increasing Digits
// https://leetcode.com/problems/monotone-increasing-digits/

#include <iostream>
#include <string>
using namespace std;

int monotoneIncreasingDigits(int N) {
    string s = to_string(N);

    int i = s.size() - 1;
    while (i > 0 && s[i] < s[i-1]) {
        s[i-1]--;
        i--;
    }

    for (int j = i+1; j < s.size(); j++) {
        s[j] = '9';
    }

    return stoi(s);
}

int main() {
    int N = 10;
    cout << "The largest number with monotone increasing digits is: " << monotoneIncreasingDigits(N) << endl;

    return 0;
}

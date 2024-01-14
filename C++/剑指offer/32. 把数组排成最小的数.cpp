#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 比较函数，决定排序规则
bool Compare(const string &a, const string &b) {
    return a + b < b + a;
}

// 主函数，将数组排成最小的数
string PrintMinNumber(vector<int> &numbers) {
    vector<string> strs;
    for (int number : numbers) {
        strs.push_back(to_string(number));
    }
    sort(strs.begin(), strs.end(), Compare);
    
    string result;
    for (const string &str : strs) {
        result += str;
    }
    return result;
}

int main() {
    vector<int> numbers = {3, 32, 321};
    string minNumber = PrintMinNumber(numbers);
    cout << "The minimum number is: " << minNumber << endl;
    return 0;
}

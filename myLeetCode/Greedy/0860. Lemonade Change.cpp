// 860. Lemonade Change
// https://leetcode.com/problems/lemonade-change/  

#include <iostream>
#include <vector>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (int bill : bills) {
        if (bill == 5) five++;
        else if (bill == 10) { ten++; five--; }
        else {
            if (ten > 0) { ten--; five--; }
            else five -= 3;
        }
        if (five < 0 || ten < 0) return false;
    }
    return true;
}

int main() {
     vector<int> bills = {5, 5, 5, 10, 20};

     cout << "bills=[";
     for (int b : bills) {
          cout << b << ",";
     }
     cout << "]" << endl;
     cout << "Output: " << boolalpha << lemonadeChange(bills) << endl;
     return 0;
}

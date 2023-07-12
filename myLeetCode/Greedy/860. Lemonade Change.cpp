// 860. Lemonade Change
// https://leetcode.com/problems/lemonade-change/  

#include <iostream>
#include <vector>

bool lemonadeChange(std::vector<int>& bills) {
    int five = 0, ten = 0;

    for (int bill : bills) {
        if (bill == 5) {
            five++;
        } else if (bill == 10) {
            if (five == 0) return false;
            five--;
            ten++;
        } else {
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::vector<int> bills1 = {5,5,5,10,20}; // Expected output:true
    std::cout << std::boolalpha << lemonadeChange(bills1) << std::endl;

    std::vector<int> bills2 = {5,5,10,10,20}; // Expected output:false
    std::cout << std::boolalpha << lemonadeChange(bills2) << std::endl;

    return 0;
}

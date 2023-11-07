#include <iostream>
#include <cmath>

using namespace std;

// 函数声明
int NumberOf1Between1AndN_Solution(int n);

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    int count = NumberOf1Between1AndN_Solution(n);
    cout << "The number of digit 1 appearing from 1 to " << n << " is: " << count << endl;
    return 0;
}

// 函数定义
int NumberOf1Between1AndN_Solution(int n) {
    int count = 0;
    for (long long i = 1; i <= n; i *= 10) {
        // 分别计算个位、十位、百位...上出现1的次数
        long long divider = i * 10;
        count += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
    }
    return count;
}

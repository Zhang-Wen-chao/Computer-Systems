#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            // 如果当前a[i]比x大，继续寻找
            continue;
        } else {
            // 如果找到比x小的值并且x比a[i]大时交换
            swap(a[i], x);
            swaps++;
        }

        // 交换后检查是否形成了有序序列
        bool sorted = true;
        for (int j = 1; j < n; j++) {
            if (a[j-1] > a[j]) {
                sorted = false;
                break;
            }
        }
        // 如果数组已经有序，返回交换次数
        if (sorted) {
            cout << swaps << endl;
            return 0;
        }
    }
    
    // 如果遍历完都无法有序，输出-1
    cout << -1 << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int min_operations(vector<long long>& nums) {
    int operations = 0;
    int odd_count = 0;
    int even_count = 0;
    int min_steps_to_odd = INT_MAX;

    // Step 1: 统计奇数和偶数的数量
    for (auto& num : nums) {
        if (num % 2 == 0) {
            even_count++;
            int steps = 0;
            long long temp = num;
            while (temp % 2 == 0) {
                temp /= 2;
                steps++;
            }
            min_steps_to_odd = min(min_steps_to_odd, steps);
        } else {
            odd_count++;
        }
    }

    // Step 2: 根据奇数和偶数的数量决定操作策略
    if (odd_count > 0) {
        // 如果有奇数，直接用一个奇数合并所有偶数
        operations = even_count;
    } else {
        // 如果没有奇数，选一个偶数变成奇数
        operations = even_count + min_steps_to_odd - 1;
    }

    return operations;
}

int main() {
    int T;
    cin >> T;  // 读取测试用例数
    while (T--) {
        int n;
        cin >> n;  // 读取数组长度
        vector<long long> nums(n);

        for (int i = 0; i < n; ++i) {
            cin >> nums[i];  // 读取数组元素
        }

        int result = min_operations(nums);
        cout << result << endl;  // 输出每组测试的最少操作次数
    }

    return 0;
}

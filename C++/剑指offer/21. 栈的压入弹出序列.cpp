#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool IsPopOrder(const vector<int>& pushV, const vector<int>& popV) {
    if (pushV.size() != popV.size()) return false;
    stack<int> stack;
    int j = 0; // 用于标记弹出序列的位置

    // 遍历压入序列
    for (int i = 0; i < pushV.size(); ++i) {
        stack.push(pushV[i]); // 将压入序列中的每个数都压入栈中
        // 循环判断与弹出序列当前位置匹配的数
        while (!stack.empty() && stack.top() == popV[j]) {
            stack.pop(); // 弹出
            j++; // 弹出序列移动到下一个位置
        }
    }

    return stack.empty(); // 如果栈为空，则说明弹出序列是正确的
}

int main() {
    vector<int> push = {1, 2, 3, 4, 5};
    vector<int> pop = {4, 5, 3, 2, 1};

    if (IsPopOrder(push, pop)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

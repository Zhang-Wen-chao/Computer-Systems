#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

class MinStack {
private:
    stack<int> s1; // 主栈，存储所有元素
    stack<int> s2; // 辅助栈，存储最小元素

public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= s2.top()) { // 注意这里是<=，保证了元素值相同的情况下，辅助栈也要压入数据
            s2.push(x);
        }
    }

    void pop() {
        if (s1.top() == s2.top()) {
            s2.pop();
        }
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int min() {
        return s2.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Min: " << minStack.min() << endl; // 返回 -3.
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;  // 返回 0.
    cout << "Min: " << minStack.min() << endl; // 返回 -2.

    return 0;
}

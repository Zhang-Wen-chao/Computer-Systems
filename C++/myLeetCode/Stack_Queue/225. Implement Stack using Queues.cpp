// 225. Implement Stack using Queues
// https://leetcode.com/problems/implement-stack-using-queues/

#include <iostream>
#include <queue>

class MyStack {
private:
    std::queue<int> q1;
    std::queue<int> q2;
    int topElement; // 用于存储栈顶元素的变量

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x); // 将元素压入 q1
        topElement = x; // 更新栈顶元素
    }
    
    int pop() {
        while (q1.size() > 1) {
            topElement = q1.front(); // 记录即将被弹出的元素作为新的栈顶元素
            q2.push(topElement); // 将前 n-1 个元素从 q1 移动到 q2
            q1.pop();
        }
        
        int poppedElement = q1.front(); // 弹出栈顶元素
        q1.pop();
        
        std::swap(q1, q2); // 交换 q1 和 q2，确保 q1 为空队列
        
        return poppedElement;
    }
    
    int top() {
        return topElement; // 返回栈顶元素
    }
    
    bool empty() {
        return q1.empty(); // 判断栈是否为空
    }
};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << stack.top() << std::endl; // Output: 3
    std::cout << stack.pop() << std::endl; // Output: 3
    std::cout << stack.top() << std::endl; // Output: 2
    std::cout << stack.empty() << std::endl; // Output: false
    return 0;
}

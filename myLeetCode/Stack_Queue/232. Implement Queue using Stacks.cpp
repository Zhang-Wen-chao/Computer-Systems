// 232. Implement Queue using Stacks
// https://leetcode.com/problems/implement-queue-using-stacks/

#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> inStack;
    std::stack<int> outStack;

public:
    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int front = outStack.top();
        outStack.pop();
        return front;
    }

    int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    std::cout << "Front element: " << queue.peek() << std::endl;
    queue.pop();
    std::cout << "Front element: " << queue.peek() << std::endl;

    std::cout << "Is queue empty? " << std::boolalpha << queue.empty() << std::endl;

    return 0;
}

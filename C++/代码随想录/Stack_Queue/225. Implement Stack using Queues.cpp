// 225. Implement Stack using Queues
// https://leetcode.com/problems/implement-stack-using-queues/

#include <iostream>
#include <queue>

class MyStack {
private:
    std::queue<int> mainQueue, auxQueue;

public:
    MyStack() {}

    void push(int x) {
        auxQueue.push(x);
        while (!mainQueue.empty()) {
            auxQueue.push(mainQueue.front());
            mainQueue.pop();
        }
        std::swap(mainQueue, auxQueue);
    }

    int pop() {
        int topElem = mainQueue.front();
        mainQueue.pop();
        return topElem;
    }

    int top() {
        return mainQueue.front();
    }

    bool empty() {
        return mainQueue.empty();
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

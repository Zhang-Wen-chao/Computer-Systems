#include <iostream>
#include <stack>
#include <exception>

template <typename T>
class CQueue {
public:
    CQueue() {}
    ~CQueue() {}

    // 在队列末尾添加一个元素
    void appendTail(const T& node) {
        stack1.push(node);
    }

    // 删除队列的第一个元素
    T deleteHead() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                T& data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        if (stack2.empty()) {
            throw std::runtime_error("queue is empty");
        }
        T head = stack2.top();
        stack2.pop();
        return head;
    }

private:
    std::stack<T> stack1; // 插入栈
    std::stack<T> stack2; // 删除栈
};

int main() {
    CQueue<int> queue;
    
    // 添加元素到队列
    queue.appendTail(1);
    queue.appendTail(2);
    queue.appendTail(3);

    // 删除队列的头元素并打印
    try {
        std::cout << "The first element deleted from queue is: " << queue.deleteHead() << std::endl;
        std::cout << "The second element deleted from queue is: " << queue.deleteHead() << std::endl;
        std::cout << "The third element deleted from queue is: " << queue.deleteHead() << std::endl;
    } catch (std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

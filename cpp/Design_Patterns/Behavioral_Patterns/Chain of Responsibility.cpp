/*
Chain of Responsibility

Intent
Avoid coupling the sender of a request to its receiver by giving more than one object a chance to handle the request. Chain the receiving objects and pass the request along the chain until an object handles it.

Applicability
Use Chain of Responsibility when

• more than one object may handle a request, and the handler isn’t known a priori. The handler should be ascertained automatically.

• you want to issue a request to one of several objects without specifying the receiver explicitly.

• the set of objects that can handle a request should be specified dynamically.
*/
#include <iostream>
#include <string>

// Handler 抽象类
class Handler {
public:
    virtual ~Handler() {}
    virtual void setNext(Handler* next) = 0;
    virtual void handleRequest(const std::string& request) = 0;
};

// 具体的 Handler 实现
class ConcreteHandlerA : public Handler {
public:
    void setNext(Handler* next) override {
        m_nextHandler = next;
    }

    void handleRequest(const std::string& request) override {
        if (request == "A") {
            std::cout << "ConcreteHandlerA: Handling request " << request << std::endl;
        } else if (m_nextHandler != nullptr) {
            std::cout << "ConcreteHandlerA: Passing request " << request << " to next handler." << std::endl;
            m_nextHandler->handleRequest(request);
        } else {
            std::cout << "ConcreteHandlerA: Unable to handle request " << request << std::endl;
        }
    }

private:
    Handler* m_nextHandler;
};

class ConcreteHandlerB : public Handler {
public:
    void setNext(Handler* next) override {
        m_nextHandler = next;
    }

    void handleRequest(const std::string& request) override {
        if (request == "B") {
            std::cout << "ConcreteHandlerB: Handling request " << request << std::endl;
        } else if (m_nextHandler != nullptr) {
            std::cout << "ConcreteHandlerB: Passing request " << request << " to next handler." << std::endl;
            m_nextHandler->handleRequest(request);
        } else {
            std::cout << "ConcreteHandlerB: Unable to handle request " << request << std::endl;
        }
    }

private:
    Handler* m_nextHandler;
};

// 客户端代码
int main() {
    // 创建责任链
    Handler* handlerA = new ConcreteHandlerA();
    Handler* handlerB = new ConcreteHandlerB();
    handlerA->setNext(handlerB);

    // 处理请求
    handlerA->handleRequest("A");
    handlerA->handleRequest("B");
    handlerA->handleRequest("C");

    // 释放资源
    delete handlerA;
    delete handlerB;

    return 0;
}
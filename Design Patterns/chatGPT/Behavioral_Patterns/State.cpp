/*
State

Intent
Allow an object to alter its behavior when its internal state changes. The object will appear to change its class.

Applicability
Use the State pattern in either of the following cases:

• An object’s behavior depends on its state, and it must change its behavior at run-time depending on that state.

• Operations have large, multipart conditional statements that depend on the object’s state. This state is usually represented by one or more enumerated constants. Often, several operations will contain this same conditional structure. The State pattern puts each branch of the conditional in a separate class. This lets you treat the object’s state as an object in its own right that can vary independently from other objects.
*/
#include <iostream>
#include <string>
#include <memory>

// 上下文 - 包含一个State对象，并将操作委托给State处理
class Context;

// State类 - 定义一个接口以封装与Context相关的行为
class State {
public:
    virtual void handle(Context& context) = 0;
    virtual std::string getName() const = 0;
    virtual void printTransition() const = 0;
    virtual void setState(Context& context, std::unique_ptr<State> newState) = 0;
};

// ConcreteState类 - 实现State接口的具体状态类
class ConcreteStateA : public State {
public:
    void handle(Context& context) override;
    std::string getName() const override {
        return "ConcreteStateA";
    }
    void printTransition() const override {
        std::cout << "Transitioning to ConcreteStateA." << std::endl;
    }
    void setState(Context& context, std::unique_ptr<State> newState) override;
};

class ConcreteStateB : public State {
public:
    void handle(Context& context) override;
    std::string getName() const override {
        return "ConcreteStateB";
    }
    void printTransition() const override {
        std::cout << "Transitioning to ConcreteStateB." << std::endl;
    }
    void setState(Context& context, std::unique_ptr<State> newState) override;
};

// 上下文类
class Context {
private:
    std::unique_ptr<State> state;

public:
    Context() : state(nullptr) {}

    void setState(std::unique_ptr<State> newState) {
        state = std::move(newState);
    }

    void request() {
        if (state) {
            std::cout << "Handling the request in " << state->getName() << "." << std::endl;
            std::cout << "State address: " << state.get() << std::endl;
            state->printTransition();  // 输出状态转移情况
            state->handle(*this);
        }
    }
};

void ConcreteStateA::handle(Context& context) {
    // 根据需要更改状态
    context.setState(std::make_unique<ConcreteStateB>());
}

void ConcreteStateA::setState(Context& context, std::unique_ptr<State> newState) {
    context.setState(std::move(newState));
}

void ConcreteStateB::handle(Context& context) {
    // 根据需要更改状态
    context.setState(std::make_unique<ConcreteStateA>());
}

void ConcreteStateB::setState(Context& context, std::unique_ptr<State> newState) {
    context.setState(std::move(newState));
}

int main() {
    Context context;

    std::cout << "Starting in the initial state." << std::endl;

    // 初始状态
    context.setState(std::make_unique<ConcreteStateA>());

    // split line
    std::cout << "------------------------" << std::endl;
    
    context.request();

    // split line
    std::cout << "------------------------" << std::endl;

    // 状态转换
    context.request();

    // split line
    std::cout << "------------------------" << std::endl;

    // 状态转换
    context.request();

    return 0;
}

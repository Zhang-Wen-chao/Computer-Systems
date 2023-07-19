/*
Strategy

Intent
Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from clients that use it.

Applicability
Use the Strategy pattern when

• many related classes differ only in their behavior. Strategies provide a way to configure a class with one of many behaviors.

• you need different variants of an algorithm. For example, you might define algorithms reflecting different space/time trade-offs. Strategies can be used when these variants are implemented as a class hierarchy of algorithms [HO87].

• an algorithm uses data that clients shouldn’t know about. Use the Strategy pattern to avoid exposing complex, algorithm-specific data structures.

• a class defines many behaviors, and these appear as multiple conditional statements in its operations. Instead of many conditionals, move related conditional branches into their own Strategy class.
*/
#include <iostream>
#include <string>

// 策略接口
class Strategy {
public:
    virtual void execute() = 0;
};

// 具体策略类 A
class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        std::cout << "Executing strategy A." << std::endl;
    }
};

// 具体策略类 B
class ConcreteStrategyB : public Strategy {
public:
    void execute() override {
        std::cout << "Executing strategy B." << std::endl;
    }
};

// 上下文类
class Context {
private:
    Strategy* strategy;

public:
    Context(Strategy* strategy) : strategy(strategy) {}

    void setStrategy(Strategy* newStrategy) {
        strategy = newStrategy;
    }

    void executeStrategy() {
        if (strategy) {
            strategy->execute();
        }
    }
};

int main() {
    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;

    Context context(&strategyA);

    // 执行策略 A
    context.executeStrategy();

    // 更改策略为 B
    context.setStrategy(&strategyB);

    // 执行策略 B
    context.executeStrategy();

    return 0;
}
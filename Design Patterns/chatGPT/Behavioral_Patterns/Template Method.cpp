/*
Template Method

Intent
Define the skeleton of an algorithm in an operation, deferring some steps to subclasses. Template Method lets subclasses redefine certain steps of an algorithm without changing the algorithm’s structure.

Applicability
The Template Method pattern should be used

• to implement the invariant parts of an algorithm once and leave it up to subclasses to implement the behavior that can vary.

• when common behavior among subclasses should be factored and localized in a common class to avoid code duplication. This is a good example of “refactoring to generalize” as described by Opdyke and Johnson [OJ93]. You first identify the differences in the existing code and then separate the differences into new operations. Finally, you replace the differing code with a template method that calls one of these new operations.

• to control subclasses extensions. You can define a template method that calls “hook” operations (see Consequences) at specific points, thereby permitting extensions only at those points.
*/
#include <iostream>

// 基类，定义模板方法以及具体的步骤
class BaseClass {
public:
    // 模板方法
    void templateMethod() {
        stepOne();
        stepTwo();
        stepThree();
    }

    // 抽象的步骤，需要在子类中实现
    virtual void stepOne() = 0;
    virtual void stepTwo() = 0;

    // 钩子方法，提供默认实现，子类可以选择性地重写
    virtual void stepThree() {
        std::cout << "BaseClass: Default implementation of Step Three" << std::endl;
    }
};

// 具体子类A
class ConcreteClassA : public BaseClass {
public:
    void stepOne() override {
        std::cout << "ConcreteClassA: Step One" << std::endl;
    }

    void stepTwo() override {
        std::cout << "ConcreteClassA: Step Two" << std::endl;
    }
};

// 具体子类B
class ConcreteClassB : public BaseClass {
public:
    void stepOne() override {
        std::cout << "ConcreteClassB: Step One" << std::endl;
    }

    void stepTwo() override {
        std::cout << "ConcreteClassB: Step Two" << std::endl;
    }
};

int main() {
    BaseClass* objA = new ConcreteClassA();
    BaseClass* objB = new ConcreteClassB();

    // 调用模板方法
    objA->templateMethod();
    std::cout << "---------------" << std::endl;
    objB->templateMethod();

    delete objA;
    delete objB;

    return 0;
}
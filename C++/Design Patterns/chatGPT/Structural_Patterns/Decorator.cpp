/*
Decorator

Intent
Attach additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.

Applicability
Use Decorator

• to add responsibilities to individual objects dynamically and transparently, that is, without affecting other objects.

• for responsibilities that can be withdrawn.

• when extension by subclassing is impractical. Sometimes a large number of independent extensions are possible and would produce an explosion of subclasses to support every combination. Or a class definition may be hidden or otherwise unavailable for subclassing.
*/
#include <iostream>

// 抽象组件类
class Component {
public:
    virtual void operation() const = 0;
};

// 具体组件类
class ConcreteComponent : public Component {
public:
    void operation() const {
        std::cout << "Concrete Component operation" << std::endl;
    }
};

// 抽象装饰器类
class Decorator : public Component {
public:
    Decorator(Component* component) : m_component(component) {}

    void operation() const {
        if (m_component) {
            m_component->operation();
        }
    }

protected:
    Component* m_component;
};

// 具体装饰器类A
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}

    void operation() const {
        Decorator::operation();
        additionalOperationA();
    }

    void additionalOperationA() const {
        std::cout << "Concrete Decorator A additional operation" << std::endl;
    }
};

// 具体装饰器类B
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}

    void operation() const {
        Decorator::operation();
        additionalOperationB();
    }

    void additionalOperationB() const {
        std::cout << "Concrete Decorator B additional operation" << std::endl;
    }
};

// 客户端代码
int main() {
    Component* component = new ConcreteComponent();
    component->operation();

    Component* decoratedComponentA = new ConcreteDecoratorA(component);
    decoratedComponentA->operation();

    Component* decoratedComponentB = new ConcreteDecoratorB(decoratedComponentA);
    decoratedComponentB->operation();

    delete decoratedComponentB;
    delete decoratedComponentA;
    delete component;

    return 0;
}
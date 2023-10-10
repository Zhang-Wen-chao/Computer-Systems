/*
Facade

Intent
Provide a unified interface to a set of interfaces in a subsystem. Facade defines a higher-level interface that makes the subsystem easier to use.

Applicability
Use the Facade pattern when

• you want to provide a simple interface to a complex subsystem. Subsystems often get more complex as they evolve. Most patterns, when applied, result in more and smaller classes. This makes the subsystem more reusable and easier to customize, but it also becomes harder to use for clients that don’t need to customize it. A facade can provide a simple default view of the subsystem that is good enough for most clients. Only clients needing more customizability will need to look beyond the facade.

• there are many dependencies between clients and the implementation classes of an abstraction. Introduce a facade to decouple the subsystem from clients and other subsystems, thereby promoting subsystem independence and portability.

• you want to layer your subsystems. Use a facade to define an entry point to each subsystem level. If subsystems are dependent, then you can simplify the dependencies between them by making them communicate with each other solely through their facades.
*/
#include <iostream>

// 子系统A
class SubsystemA {
public:
    void operationA() const {
        std::cout << "Subsystem A operation" << std::endl;
    }
};

// 子系统B
class SubsystemB {
public:
    void operationB() const {
        std::cout << "Subsystem B operation" << std::endl;
    }
};

// 子系统C
class SubsystemC {
public:
    void operationC() const {
        std::cout << "Subsystem C operation" << std::endl;
    }
};

// Facade类
class Facade {
public:
    Facade() {
        m_subsystemA = new SubsystemA();
        m_subsystemB = new SubsystemB();
        m_subsystemC = new SubsystemC();
    }

    ~Facade() {
        delete m_subsystemA;
        delete m_subsystemB;
        delete m_subsystemC;
    }

    void operation() const {
        m_subsystemA->operationA();
        m_subsystemB->operationB();
        m_subsystemC->operationC();
    }

private:
    SubsystemA* m_subsystemA;
    SubsystemB* m_subsystemB;
    SubsystemC* m_subsystemC;
};

// 客户端代码
int main() {
    Facade facade;
    facade.operation();

    return 0;
}
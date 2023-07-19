/*
Bridge

Intent
Decouple an abstraction from its implementation so that the two can vary independently.

Applicability
Use the Bridge pattern when

• you want to avoid a permanent binding between an abstraction and its implementation. This might be the case, for example, when the implementation must be selected or switched at run-time.

• both the abstractions and their implementations should be extensible by subclassing. In this case, the Bridge pattern lets you combine the different abstractions and implementations and extend them independently.

• changes in the implementation of an abstraction should have no impact on clients; that is, their code should not have to be recompiled.


All operations on Window subclasses are implemented in terms of abstract operations from the WindowImp interface. This decouples the window abstractions from the various platform-specific implementations. We refer to the relationship between Window and WindowImp as a bridge, because it bridges the abstraction and its implementation, letting them vary independently.

Applicability
Use the Bridge pattern when

• you want to avoid a permanent binding between an abstraction and its implementation. This might be the case, for example, when the implementation must be selected or switched at run-time.

• both the abstractions and their implementations should be extensible by subclassing. In this case, the Bridge pattern lets you combine the different abstractions and implementations and extend them independently.

• changes in the implementation of an abstraction should have no impact on clients; that is, their code should not have to be recompiled.

• (C++) you want to hide the implementation of an abstraction completely from clients. In C++ the representation of a class is visible in the class interface.

• you have a proliferation of classes as shown earlier in the first Motivation diagram. Such a class hierarchy indicates the need for splitting an object into two parts. Rumbaugh uses the term “nested generalizations” [RBP+91] to refer to such class hierarchies.

• you want to share an implementation among multiple objects (perhaps using reference counting), and this fact should be hidden from the client. A simple example is Coplien’s String class [Cop92], in which multiple objects can share the same string representation (StringRep).
*/
#include <iostream>

// 实现接口
class Implementor {
public:
    virtual void operationImpl() const = 0;
};

// 具体实现类A
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() const {
        std::cout << "Concrete Implementor A" << std::endl;
    }
};

// 具体实现类B
class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() const {
        std::cout << "Concrete Implementor B" << std::endl;
    }
};

// 抽象类
class Abstraction {
public:
    Abstraction(Implementor* implementor) : m_implementor(implementor) {}
    virtual void operation() const = 0;

protected:
    Implementor* m_implementor;
};

// 扩充抽象类A
class RefinedAbstractionA : public Abstraction {
public:
    RefinedAbstractionA(Implementor* implementor) : Abstraction(implementor) {}
    
    void operation() const {
        std::cout << "Refined Abstraction A" << std::endl;
        m_implementor->operationImpl();
    }
};

// 扩充抽象类B
class RefinedAbstractionB : public Abstraction {
public:
    RefinedAbstractionB(Implementor* implementor) : Abstraction(implementor) {}
    
    void operation() const {
        std::cout << "Refined Abstraction B" << std::endl;
        m_implementor->operationImpl();
    }
};

// 客户端代码
int main() {
    Implementor* implementorA = new ConcreteImplementorA();
    Implementor* implementorB = new ConcreteImplementorB();
    
    Abstraction* abstractionA = new RefinedAbstractionA(implementorA);
    Abstraction* abstractionB = new RefinedAbstractionB(implementorB);
    
    abstractionA->operation();
    abstractionB->operation();
    
    delete implementorA;
    delete implementorB;
    delete abstractionA;
    delete abstractionB;
    
    return 0;
}
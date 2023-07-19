/*
Prototype

Intent
Specify the kinds of objects to create using a prototypical instance, and create new objects by copying this prototype.

Applicability
Use the Prototype pattern when a system should be independent of how its products are created, composed, and represented; and

• when the classes to instantiate are specified at run-time, for example, by dynamic loading; or

• to avoid building a class hierarchy of factories that parallels the class hierarchy of products; or

• when instances of a class can have one of only a few different combinations of state. It may be more convenient to install a corresponding number of prototypes and clone them rather than instantiating the class manually, each time with the appropriate state.
*/
#include <iostream>
#include <string>

// 原型抽象类
class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void display() const = 0;
};

// 具体原型类A
class ConcretePrototypeA : public Prototype {
public:
    Prototype* clone() const {
        return new ConcretePrototypeA(*this);
    }
    
    void display() const {
        std::cout << "ConcretePrototypeA" << std::endl;
    }
};

// 具体原型类B
class ConcretePrototypeB : public Prototype {
public:
    Prototype* clone() const {
        return new ConcretePrototypeB(*this);
    }
    
    void display() const {
        std::cout << "ConcretePrototypeB" << std::endl;
    }
};

// 客户端代码
int main() {
    Prototype* prototypeA = new ConcretePrototypeA();
    Prototype* prototypeB = new ConcretePrototypeB();
    
    Prototype* cloneA = prototypeA->clone();
    Prototype* cloneB = prototypeB->clone();
    
    prototypeA->display();
    cloneA->display();
    
    prototypeB->display();
    cloneB->display();
    
    delete prototypeA;
    delete prototypeB;
    delete cloneA;
    delete cloneB;
    
    return 0;
}
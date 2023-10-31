/*
Adapter

Intent
Convert the interface of a class into another interface clients expect. Adapter lets classes work together that couldn’t otherwise because of incompatible interfaces.

Applicability
Use the Adapter pattern when

• you want to use an existing class, and its interface does not match the one you need.

• you want to create a reusable class that cooperates with unrelated or unforeseen classes, that is, classes that don’t necessarily have compatible interfaces.

• (object adapter only) you need to use several existing subclasses, but it’s impractical to adapt their interface by subclassing every one. An object adapter can adapt the interface of its parent class.
*/
#include <iostream>

// 目标接口
class Target {
public:
    virtual void request() const = 0;
};

// 适配者类
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Adaptee's specific request" << std::endl;
    }
};

// 类适配器类
class ClassAdapter : public Target, private Adaptee {
public:
    void request() const {
        specificRequest();
    }
};

// 对象适配器类
class ObjectAdapter : public Target {
public:
    ObjectAdapter(Adaptee* adaptee) : m_adaptee(adaptee) {}
    
    void request() const {
        m_adaptee->specificRequest();
    }

private:
    Adaptee* m_adaptee;
};

// 客户端代码
int main() {
    Target* adapter1 = new ClassAdapter();
    adapter1->request();
    
    Adaptee* adaptee = new Adaptee();
    Target* adapter2 = new ObjectAdapter(adaptee);
    adapter2->request();
    
    delete adapter1;
    delete adapter2;
    delete adaptee;
    
    return 0;
}
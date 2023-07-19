/*
Visitor

Intent
Represent an operation to be performed on the elements of an object structure. Visitor lets you define a new operation without changing the classes of the elements on which it operates.

Applicability
image
image
With the Visitor pattern, you define two class hierarchies: one for the elements being operated on (the Node hierarchy) and one for the visitors that define operations on the elements (the NodeVisitor hierarchy). You create a new operation by adding a new subclass to the visitor class hierarchy. As long as the grammar that the compiler accepts doesn’t change (that is, we don’t have to add new Node subclasses), we can add new functionality simply by defining new NodeVisitor subclasses.

Applicability
Use the Visitor pattern when

• an object structure contains many classes of objects with differing interfaces, and you want to perform operations on these objects that depend on their concrete classes.

• many distinct and unrelated operations need to be performed on objects in an object structure, and you want to avoid “polluting” their classes with these operations. Visitor lets you keep related operations together by defining them in one class. When the object structure is shared by many applications, use Visitor to put operations in just those applications that need them.

• the classes defining the object structure rarely change, but you often want to define new operations over the structure. Changing the object structure classes requires redefining the interface to all visitors, which is potentially costly. If the object structure classes change often, then it’s probably better to define the operations in those classes.
*/
#include <iostream>

// 前向声明
class ConcreteElementA;
class ConcreteElementB;

// 访问者接口
class Visitor {
public:
    virtual void visit(ConcreteElementA* element) = 0;
    virtual void visit(ConcreteElementB* element) = 0;
};

// 具体访问者 A
class ConcreteVisitorA : public Visitor {
public:
    void visit(ConcreteElementA* element) override {
        std::cout << "ConcreteVisitorA visits ConcreteElementA." << std::endl;
    }

    void visit(ConcreteElementB* element) override {
        std::cout << "ConcreteVisitorA visits ConcreteElementB." << std::endl;
    }
};

// 具体访问者 B
class ConcreteVisitorB : public Visitor {
public:
    void visit(ConcreteElementA* element) override {
        std::cout << "ConcreteVisitorB visits ConcreteElementA." << std::endl;
    }

    void visit(ConcreteElementB* element) override {
        std::cout << "ConcreteVisitorB visits ConcreteElementB." << std::endl;
    }
};

// 元素接口
class Element {
public:
    virtual void accept(Visitor* visitor) = 0;
};

// 具体元素 A
class ConcreteElementA : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visit(this);
    }
};

// 具体元素 B
class ConcreteElementB : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visit(this);
    }
};

// 对象结构，存储元素并提供访问的接口
class ObjectStructure {
private:
    Element* elements[2];

public:
    ObjectStructure() {
        elements[0] = new ConcreteElementA();
        elements[1] = new ConcreteElementB();
    }

    ~ObjectStructure() {
        delete elements[0];
        delete elements[1];
    }

    void accept(Visitor* visitor) {
        for (int i = 0; i < 2; i++) {
            elements[i]->accept(visitor);
        }
    }
};

int main() {
    Visitor* visitorA = new ConcreteVisitorA();
    Visitor* visitorB = new ConcreteVisitorB();

    ObjectStructure objectStructure;

    // 使用具体访问者A进行访问
    objectStructure.accept(visitorA);

    std::cout << "---------------------" << std::endl;

    // 使用具体访问者B进行访问
    objectStructure.accept(visitorB);

    delete visitorA;
    delete visitorB;

    return 0;
}
/*
Factory Method

Intent
Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.

Applicability
Use the Factory Method pattern when

• a class can’t anticipate the class of objects it must create.

• a class wants its subclasses to specify the objects it creates.

• classes delegate responsibility to one of several helper subclasses, and you want to localize the knowledge of which helper subclass is the delegate.
*/

#include <iostream>

// 抽象产品
class Product {
public:
    virtual void display() = 0;
};

// 具体产品A
class ConcreteProductA : public Product {
public:
    void display() {
        std::cout << "Concrete Product A" << std::endl;
    }
};

// 具体产品B
class ConcreteProductB : public Product {
public:
    void display() {
        std::cout << "Concrete Product B" << std::endl;
    }
};

// 抽象创建者
class Creator {
public:
    virtual Product* createProduct() = 0;
};

// 具体创建者A
class ConcreteCreatorA : public Creator {
public:
    Product* createProduct() {
        return new ConcreteProductA();
    }
};

// 具体创建者B
class ConcreteCreatorB : public Creator {
public:
    Product* createProduct() {
        return new ConcreteProductB();
    }
};

int main() {
    Creator* creatorA = new ConcreteCreatorA();
    Product* productA = creatorA->createProduct();
    productA->display();

    Creator* creatorB = new ConcreteCreatorB();
    Product* productB = creatorB->createProduct();
    productB->display();

    delete creatorA;
    delete productA;
    delete creatorB;
    delete productB;

    return 0;
}
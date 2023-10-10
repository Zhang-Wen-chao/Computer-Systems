/*
Abstract Factory

Intent
Provide an interface for creating families of related or dependent objects without specifying their concrete classes.

Applicability
Use the Abstract Factory pattern when

• a system should be independent of how its products are created, composed, and represented.

• a system should be configured with one of multiple families of products.

• a family of related product objects is designed to be used together, and you need to enforce this constraint.

• you want to provide a class library of products, and you want to reveal just their interfaces, not their implementations.
*/

#include <iostream>

// 抽象产品A
class AbstractProductA {
public:
    virtual void display() = 0;
};

// 具体产品A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void display() {
        std::cout << "Concrete Product A1" << std::endl;
    }
};

// 具体产品A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void display() {
        std::cout << "Concrete Product A2" << std::endl;
    }
};

// 抽象产品B
class AbstractProductB {
public:
    virtual void display() = 0;
};

// 具体产品B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void display() {
        std::cout << "Concrete Product B1" << std::endl;
    }
};

// 具体产品B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void display() {
        std::cout << "Concrete Product B2" << std::endl;
    }
};

// 抽象工厂
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

// 具体工厂1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() {
        return new ConcreteProductA1();
    }
    
    AbstractProductB* createProductB() {
        return new ConcreteProductB1();
    }
};

// 具体工厂2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() {
        return new ConcreteProductA2();
    }
    
    AbstractProductB* createProductB() {
        return new ConcreteProductB2();
    }
};

int main() {
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();
    productA1->display();
    productB1->display();

    AbstractFactory* factory2 = new ConcreteFactory2();
    AbstractProductA* productA2 = factory2->createProductA();
    AbstractProductB* productB2 = factory2->createProductB();
    productA2->display();
    productB2->display();

    delete factory1;
    delete productA1;
    delete productB1;
    delete factory2;
    delete productA2;
    delete productB2;

    return 0;
}
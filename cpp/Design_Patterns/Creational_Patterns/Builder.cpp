/*
Builder

Intent
Separate the construction of a complex object from its representation so that the same construction process can create different representations.

Applicability
Use the Builder pattern when

• the algorithm for creating a complex object should be independent of the parts that make up the object and how they’re assembled.

• the construction process must allow different representations for the object that’s constructed.
*/
#include <iostream>
#include <string>

// 产品类
class Product {
public:
    void setPartA(const std::string& partA) {
        m_partA = partA;
    }
    
    void setPartB(const std::string& partB) {
        m_partB = partB;
    }
    
    void setPartC(const std::string& partC) {
        m_partC = partC;
    }
    
    void display() {
        std::cout << "Part A: " << m_partA << std::endl;
        std::cout << "Part B: " << m_partB << std::endl;
        std::cout << "Part C: " << m_partC << std::endl;
    }

private:
    std::string m_partA;
    std::string m_partB;
    std::string m_partC;
};

// 抽象建造者类
class AbstractBuilder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product* getProduct() = 0;
};

// 具体建造者类
class ConcreteBuilder : public AbstractBuilder {
public:
    ConcreteBuilder() {
        m_product = new Product();
    }
    
    void buildPartA() {
        m_product->setPartA("Part A");
    }
    
    void buildPartB() {
        m_product->setPartB("Part B");
    }
    
    void buildPartC() {
        m_product->setPartC("Part C");
    }
    
    Product* getProduct() {
        return m_product;
    }

private:
    Product* m_product;
};

// 指导者类
class Director {
public:
    void constructProduct(AbstractBuilder* builder) {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
    }
};

int main() {
    Director director;
    ConcreteBuilder builder;
    
    director.constructProduct(&builder);
    Product* product = builder.getProduct();
    product->display();
    
    delete product;
    
    return 0;
}
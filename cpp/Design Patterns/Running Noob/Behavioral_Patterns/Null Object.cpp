#include <iostream>
#include <string>
#include <algorithm>

class AbstractCustomer {
protected:
    std::string name;

public:
    virtual bool isNil() = 0;
    virtual std::string getName() = 0;
};

class RealCustomer : public AbstractCustomer {
public:
    RealCustomer(const std::string& name) {
        this->name = name;
    }

    std::string getName() override {
        return name;
    }

    bool isNil() override {
        return false;
    }
};

class NullCustomer : public AbstractCustomer {
public:
    std::string getName() override {
        return "Not Available in Customer Database";
    }

    bool isNil() override {
        return true;
    }
};

class CustomerFactory {
public:
    static const std::string names[];

    static size_t arraySize(const std::string* arr, size_t n) {
        return n;
    }

    static AbstractCustomer* getCustomer(const std::string& name) {
        auto iter = std::find_if(names, names + arraySize(names, 3),
                                 [name](const std::string& n) {
                                     return n == name;
                                 });

        if (iter != names + arraySize(names, 3)) {
            return new RealCustomer(*iter);
        }

        return new NullCustomer();
    }
};

const std::string CustomerFactory::names[] = {"Rob", "Joe", "Julie"};

int main() {
    AbstractCustomer* customer1 = CustomerFactory::getCustomer("Rob");
    AbstractCustomer* customer2 = CustomerFactory::getCustomer("Bob");
    AbstractCustomer* customer3 = CustomerFactory::getCustomer("Julie");
    AbstractCustomer* customer4 = CustomerFactory::getCustomer("Laura");

    std::cout << "Customers:" << std::endl;
    std::cout << customer1->getName() << std::endl;
    std::cout << customer2->getName() << std::endl;
    std::cout << customer3->getName() << std::endl;
    std::cout << customer4->getName() << std::endl;

    delete customer1;
    delete customer2;
    delete customer3;
    delete customer4;

    return 0;
}
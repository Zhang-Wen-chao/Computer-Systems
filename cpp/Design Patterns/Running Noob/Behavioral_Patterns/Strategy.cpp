#include <iostream>

class Strategy {
public:
    virtual int doOperation(int num1, int num2) = 0;
};

class OperationAdd : public Strategy {
public:
    int doOperation(int num1, int num2) override {
        return num1 + num2;
    }
};

class OperationSubtract : public Strategy {
public:
    int doOperation(int num1, int num2) override {
        return num1 - num2;
    }
};

class OperationMultiply : public Strategy {
public:
    int doOperation(int num1, int num2) override {
        return num1 * num2;
    }
};

class Context {
private:
    Strategy* strategy;

public:
    Context(Strategy* strategy) : strategy(strategy) {}

    int executeStrategy(int num1, int num2) {
        return strategy->doOperation(num1, num2);
    }
};

int main() {
    Strategy* addition = new OperationAdd();
    Context contextAddition(addition);
    std::cout << "10 + 5 = " << contextAddition.executeStrategy(10, 5) << std::endl;

    Strategy* subtraction = new OperationSubtract();
    Context contextSubtraction(subtraction);
    std::cout << "10 - 5 = " << contextSubtraction.executeStrategy(10, 5) << std::endl;

    Strategy* multiplication = new OperationMultiply();
    Context contextMultiplication(multiplication);
    std::cout << "10 * 5 = " << contextMultiplication.executeStrategy(10, 5) << std::endl;

    delete addition;
    delete subtraction;
    delete multiplication;

    return 0;
}
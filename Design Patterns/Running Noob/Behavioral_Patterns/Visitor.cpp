#include <iostream>

class ComputerPartVisitor;

class ComputerPart {
public:
    virtual void accept(ComputerPartVisitor* computerPartVisitor) = 0;
};

class Keyboard : public ComputerPart {
public:
    void accept(ComputerPartVisitor* computerPartVisitor) override;
};

class Monitor : public ComputerPart {
public:
    void accept(ComputerPartVisitor* computerPartVisitor) override;
};

class Mouse : public ComputerPart {
public:
    void accept(ComputerPartVisitor* computerPartVisitor) override;
};

class Computer : public ComputerPart {
private:
    ComputerPart* parts[3];

public:
    Computer() {
        parts[0] = new Mouse();
        parts[1] = new Keyboard();
        parts[2] = new Monitor();
    }

    void accept(ComputerPartVisitor* computerPartVisitor) override;
};

class ComputerPartVisitor {
public:
    virtual void visit(Computer* computer) = 0;
    virtual void visit(Mouse* mouse) = 0;
    virtual void visit(Keyboard* keyboard) = 0;
    virtual void visit(Monitor* monitor) = 0;
};

void Keyboard::accept(ComputerPartVisitor* computerPartVisitor) {
    computerPartVisitor->visit(this);
}

void Monitor::accept(ComputerPartVisitor* computerPartVisitor) {
    computerPartVisitor->visit(this);
}

void Mouse::accept(ComputerPartVisitor* computerPartVisitor) {
    computerPartVisitor->visit(this);
}

void Computer::accept(ComputerPartVisitor* computerPartVisitor) {
    for (int i = 0; i < 3; i++) {
        parts[i]->accept(computerPartVisitor);
    }
    computerPartVisitor->visit(this);
}

class ComputerPartDisplayVisitor : public ComputerPartVisitor {
public:
    void visit(Computer* computer) override {
        std::cout << "Displaying Computer." << std::endl;
    }

    void visit(Mouse* mouse) override {
        std::cout << "Displaying Mouse." << std::endl;
    }

    void visit(Keyboard* keyboard) override {
        std::cout << "Displaying Keyboard." << std::endl;
    }

    void visit(Monitor* monitor) override {
        std::cout << "Displaying Monitor." << std::endl;
    }
};

int main() {
    ComputerPart* computer = new Computer();
    computer->accept(new ComputerPartDisplayVisitor());

    delete computer;

    return 0;
}
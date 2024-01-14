/*
Memento

Intent
Without violating encapsulation, capture and externalize an object’s internal state so that the object can be restored to this state later.

Applicability
Use the Memento pattern when

• a snapshot of (some portion of) an object’s state must be saved so that it can be restored to that state later, and

• a direct interface to obtaining the state would expose implementation details and break the object’s encapsulation.
*/
#include <iostream>
#include <string>
#include <vector>

// Memento类 - 备忘录，保存Originator的状态
class Memento {
private:
    std::string state;

public:
    Memento(const std::string& newState) : state(newState) {}

    std::string getState() const {
        return state;
    }
};

// Originator类 - 原始对象，可以创建和恢复Memento
class Originator {
private:
    std::string state;

public:
    void setState(const std::string& newState) {
        state = newState;
    }

    std::string getState() const {
        return state;
    }

    // 创建并返回Memento对象
    Memento createMemento() const {
        return Memento(state);
    }

    // 从Memento中恢复状态
    void restoreFromMemento(const Memento& memento) {
        state = memento.getState();
    }
};

// Caretaker类 - 负责存储并管理Memento对象
class Caretaker {
private:
    std::vector<Memento> mementos;

public:
    void addMemento(const Memento& memento) {
        mementos.push_back(memento);
    }

    const Memento& getMemento(int index) {
        return mementos[index];
    }
};

int main() {
    Originator originator;
    Caretaker caretaker;

    // 设定初始状态
    originator.setState("State 1");
    // 创建Memento，并将其保存到Caretaker
    caretaker.addMemento(originator.createMemento());

    // 修改状态
    originator.setState("State 2");
    // 创建Memento，并将其保存到Caretaker
    caretaker.addMemento(originator.createMemento());

    // 恢复到第一个状态
    originator.restoreFromMemento(caretaker.getMemento(0));
    std::cout << "Current state: " << originator.getState() << std::endl;

    // 恢复到第二个状态
    originator.restoreFromMemento(caretaker.getMemento(1));
    std::cout << "Current state: " << originator.getState() << std::endl;

    return 0;
}
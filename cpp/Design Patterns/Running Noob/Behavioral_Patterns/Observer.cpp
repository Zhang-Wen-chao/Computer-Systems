/*
Observer

Intent
Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

Applicability
Use the Observer pattern in any of the following situations:

• When an abstraction has two aspects, one dependent on the other. Encapsulating these aspects in separate objects lets you vary and reuse them independently.

• When a change to one object requires changing others, and you don’t know how many objects need to be changed.

• When an object should be able to notify other objects without making assumptions about who these objects are. In other words, you don’t want these objects tightly coupled.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Observer类 - 抽象观察者
class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

// Subject类 - 抽象主题
class Subject {
private:
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        observers.erase(std::remove_if(observers.begin(), observers.end(),
            [observer](Observer* o) { return o == observer; }), observers.end());
    }

    void notify(const std::string& message) {
        for (const auto& observer : observers) {
            observer->update(message);
        }
    }
};

// ConcreteObserver类 - 具体观察者
class ConcreteObserver : public Observer {
private:
    std::string name;

public:
    ConcreteObserver(const std::string& newName) : name(newName) {}

    void update(const std::string& message) override {
        std::cout << name << " received message: " << message << std::endl;
    }
};

int main() {
    Subject subject;
    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");
    ConcreteObserver observer3("Observer 3");

    // 注册观察者
    subject.attach(&observer1);
    subject.attach(&observer2);
    subject.attach(&observer3);

    // 发送通知
    subject.notify("Hello, observers!");

    // 移除观察者
    subject.detach(&observer2);

    // 再次发送通知
    subject.notify("Goodbye, observers!");

    return 0;
}
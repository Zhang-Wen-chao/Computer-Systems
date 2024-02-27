/*
Singleton

Intent
Ensure a class only has one instance, and provide a global point of access to it.

Applicability
Use the Singleton pattern when

• there must be exactly one instance of a class, and it must be accessible to clients from a well-known access point.

• when the sole instance should be extensible by subclassing, and clients should be able to use an extended instance without modifying their code.
*/

#include <iostream>

class Singleton {
private:
    static Singleton* instance;  // 唯一实例的指针
    
    // 将构造函数和析构函数设为私有，防止外部实例化和删除对象
    Singleton() {}
    ~Singleton() {}
    
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
    
    void showMessage() {
        std::cout << "Singleton Pattern" << std::endl;
    }
};

Singleton* Singleton::instance = nullptr;  // 初始化静态指针

int main() {
    Singleton* singleton = Singleton::getInstance();
    singleton->showMessage();

    return 0;
}
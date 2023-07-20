/*
3、饿汉式
./a.out >> Singleton3.txt
*/
#include <iostream>
#include <vector>
#include <thread>

class Singleton {
private:
    static Singleton instance;

    Singleton() {}

public:
    static Singleton& getInstance() {
        return instance;
    }

    void showMessage() {
        std::cout << "Hello World!" << std::endl;
    }
};

Singleton Singleton::instance; // 在类的定义外部初始化静态成员变量

void threadFunc() {
    Singleton& object = Singleton::getInstance();
    object.showMessage();
}

int main() {
    std::vector<std::thread> threads;

    // 创建多个线程，同时调用 getInstance() 方法
    for (int i = 0; i < 100; i++) {
        threads.push_back(std::thread(threadFunc));
    }

    // 等待所有线程执行完毕
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
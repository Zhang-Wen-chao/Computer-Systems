/*
2、懒汉式，线程安全
./a.out >> Singleton2.txt
*/
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class Singleton {
private:
    static Singleton* instance;
    static std::mutex mutex;

    Singleton() {}

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mutex);
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }

    void showMessage() {
        std::cout << "Hello World!" << std::endl;
    }
};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutex;

void threadFunc() {
    Singleton* object = Singleton::getInstance();
    object->showMessage();
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
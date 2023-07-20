/*
4、双检锁/双重校验锁（DCL，即 double-checked locking）
./a.out >> Singleton4.txt
*/
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

#include <atomic>

class Singleton {
private:
    static std::atomic<Singleton*> instance;
    static std::mutex mutex;

    Singleton() {}

public:
    static Singleton* getInstance() {
        Singleton* tmp = instance.load(std::memory_order_acquire);
        if (tmp == nullptr) {
            std::lock_guard<std::mutex> lock(mutex);
            tmp = instance.load(std::memory_order_relaxed);
            if (tmp == nullptr) {
                tmp = new Singleton();
                instance.store(tmp, std::memory_order_release);
            }
        }
        return tmp;
    }

    void showMessage() {
        std::cout << "Hello World!" << std::endl;
    }
};

std::atomic<Singleton*> Singleton::instance{nullptr};
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
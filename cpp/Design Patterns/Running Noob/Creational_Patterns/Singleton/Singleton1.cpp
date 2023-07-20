/*
1、懒汉式，线程不安全
是的，你的观察是正确的。在你的代码中，每个线程都会将消息追加到文件中，并且每次追加都会换行显示，这可能会掩盖掉多个线程同时执行的情况。

如果你更喜欢在终端直接输出以便更明显地看到并行的情况，你可以修改代码，将消息输出到终端而不是写入文件。下面是修改后的代码，将消息输出到终端：

./a.out >> Singleton1.txt
*/
#include <iostream>
#include <vector>
#include <thread>

class SingleObject {
private:
    static SingleObject* instance;

    SingleObject() {}

public:
    static SingleObject* getInstance() {
        if (instance == nullptr) {
            instance = new SingleObject();
        }
        return instance;
    }

    void showMessage(const std::string& message) {
        std::cout << message << std::endl;
    }
};

SingleObject* SingleObject::instance = nullptr;

void threadFunc() {
    SingleObject* object = SingleObject::getInstance();
    object->showMessage("Hello World!");
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
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void incrementCounter(int& counter)
{
    // 上锁
    std::lock_guard<std::mutex> lock(mtx);
    counter++;
}

int main()
{
    int counter = 0;
    std::thread t1(incrementCounter, std::ref(counter));
    std::thread t2(incrementCounter, std::ref(counter));
    t1.join();
    t2.join();
    std::cout << "Counter value: " << counter << std::endl;
    return 0;
}
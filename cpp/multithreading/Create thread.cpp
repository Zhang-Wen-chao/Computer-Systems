#include <iostream>
#include <thread>

void threadFunction()
{
    std::cout << "Hello from thread!" << std::endl;
}

int main()
{
    std::thread myThread(threadFunction);
    myThread.join(); // 等待线程执行完毕
    return 0;
}
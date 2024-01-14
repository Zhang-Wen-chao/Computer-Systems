#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void threadFunction()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
    cv.notify_one();
}

int main()
{
    std::thread t(threadFunction);
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return ready; });
    std::cout << "Thread is ready!" << std::endl;
    t.join();
    return 0;
}
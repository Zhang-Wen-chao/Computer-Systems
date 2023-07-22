#include <iostream>
#include <thread>
#include <future>

int add(int a, int b)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return a + b;
}

int main()
{
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::thread t([](std::promise<int>& p)
    {
        p.set_value(add(2, 3));
    }, std::ref(promise));

    std::cout << "Waiting for result..." << std::endl;
  
    // 阻塞等待结果
    int result = future.get();
    
    std::cout << "Result: " << result << std::endl;
  
    t.join();
    return 0;
}
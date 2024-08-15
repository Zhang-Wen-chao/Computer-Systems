// g++ -std=c++11 1188-design-bounded-blocking-queue.cpp -o bounded_queue


#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <vector>
#include <functional>  // for std::ref

class BoundedBlockingQueue {
private:
    std::queue<int> queue;
    std::mutex mtx;
    std::condition_variable not_full;
    std::condition_variable not_empty;
    int capacity;

public:
    BoundedBlockingQueue(int capacity) : capacity(capacity) {}

    void enqueue(int element) {
        std::unique_lock<std::mutex> lock(mtx);
        not_full.wait(lock, [this]() { return queue.size() < capacity; });
        queue.push(element);
        not_empty.notify_one();
    }

    int dequeue() {
        std::unique_lock<std::mutex> lock(mtx);
        not_empty.wait(lock, [this]() { return !queue.empty(); });
        int element = queue.front();
        queue.pop();
        not_full.notify_one();
        return element;
    }

    int size() {
        std::lock_guard<std::mutex> lock(mtx);
        return queue.size();
    }
};

// 示例代码，展示如何使用这个有限阻塞队列
void producer(BoundedBlockingQueue& queue, std::vector<int> elements) {
    for (int element : elements) {
        std::cout << "Producing " << element << std::endl;
        queue.enqueue(element);
        std::cout << "Produced " << element << std::endl;
    }
}

void consumer(BoundedBlockingQueue& queue, int count) {
    for (int i = 0; i < count; ++i) {
        int element = queue.dequeue();
        std::cout << "Consumed " << element << std::endl;
    }
}

int main() {
    BoundedBlockingQueue queue(2);  // 创建一个容量为2的有限阻塞队列

    std::vector<int> elements = {1, 2, 3, 4};  // 创建一个vector以初始化生产者

    std::thread producer_thread(producer, std::ref(queue), elements);
    std::thread consumer_thread(consumer, std::ref(queue), 4);

    producer_thread.join();
    consumer_thread.join();

    return 0;
}

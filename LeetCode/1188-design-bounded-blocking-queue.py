import threading
from collections import deque
from typing import Optional

class BoundedBlockingQueue:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.queue = deque()
        self.lock = threading.Lock()
        self.not_full = threading.Condition(self.lock)
        self.not_empty = threading.Condition(self.lock)

    def enqueue(self, element: int) -> None:
        with self.not_full:
            while len(self.queue) >= self.capacity:
                self.not_full.wait()  # 队列已满，等待空间
            self.queue.append(element)
            self.not_empty.notify()  # 通知可能等待的dequeue操作

    def dequeue(self) -> int:
        with self.not_empty:
            while len(self.queue) == 0:
                self.not_empty.wait()  # 队列为空，等待新元素
            element = self.queue.popleft()
            self.not_full.notify()  # 通知可能等待的enqueue操作
            return element

    def size(self) -> int:
        with self.lock:
            return len(self.queue)

# 示例代码，展示如何使用这个有限阻塞队列
def producer(queue: BoundedBlockingQueue, elements):
    for element in elements:
        print(f"Producing {element}")
        queue.enqueue(element)
        print(f"Produced {element}")

def consumer(queue: BoundedBlockingQueue, count: int):
    for _ in range(count):
        element = queue.dequeue()
        print(f"Consumed {element}")

if __name__ == "__main__":
    queue = BoundedBlockingQueue(2)  # 创建一个容量为2的有限阻塞队列

    producer_thread = threading.Thread(target=producer, args=(queue, [1, 2, 3, 4]))
    consumer_thread = threading.Thread(target=consumer, args=(queue, 4))

    producer_thread.start()
    consumer_thread.start()

    producer_thread.join()
    consumer_thread.join()

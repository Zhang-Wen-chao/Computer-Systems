from collections import deque

class MyStack:

    def __init__(self):
        self.queue = deque()

    def push(self, x: int) -> None:
        self.queue.append(x)
        for _ in range(len(self.queue) - 1):
            self.queue.append(self.queue.popleft())

    def pop(self) -> int:
        return self.queue.popleft()

    def top(self) -> int:
        return self.queue[0]

    def empty(self) -> bool:
        return not self.queue

# Test case
stack = MyStack()
stack.push(1)
stack.push(2)
print(stack.top())    # Returns 2
print(stack.pop())    # Returns 2
print(stack.empty())  # Returns False

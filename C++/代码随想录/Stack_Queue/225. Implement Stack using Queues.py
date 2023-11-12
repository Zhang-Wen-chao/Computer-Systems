from collections import deque

class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue1 = deque()
        self.queue2 = deque()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue1.append(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while len(self.queue1) > 1:
            self.queue2.append(self.queue1.popleft())
        res = self.queue1.popleft()
        self.queue1, self.queue2 = self.queue2, self.queue1
        return res

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.queue1[-1]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not self.queue1

# 测试用例
myStack = MyStack()
myStack.push(1)
myStack.push(2)
print(myStack.top())  # 返回 2
print(myStack.pop())  # 返回 2
print(myStack.empty())  # 返回 False

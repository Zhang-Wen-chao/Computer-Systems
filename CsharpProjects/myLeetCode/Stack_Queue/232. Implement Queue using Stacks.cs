// 232. Implement Queue using Stacks
// https://leetcode.com/problems/implement-queue-using-stacks/

using System.Collections.Generic;

public class MyQueue {

    private Stack<int> inputStack;
    private Stack<int> outputStack;
    
    public MyQueue() {
        inputStack = new Stack<int>();
        outputStack = new Stack<int>();
    }
    
    public void Push(int x) {
        inputStack.Push(x);
    }
    
    public int Pop() {
        MoveInputToOutputIfNecessary();
        return outputStack.Pop();
    }
    
    public int Peek() {
        MoveInputToOutputIfNecessary();
        return outputStack.Peek();
    }
    
    public bool Empty() {
        return inputStack.Count == 0 && outputStack.Count == 0;
    }
    
    private void MoveInputToOutputIfNecessary() {
        if (outputStack.Count == 0) {
            while (inputStack.Count > 0) {
                outputStack.Push(inputStack.Pop());
            }
        }
    }
}
public class Program {
    public static void Main() {
        MyQueue queue = new MyQueue();

        queue.Push(1);
        queue.Push(2);
        int peek1 = queue.Peek();   // returns 1
        int pop1 = queue.Pop();     // returns 1
        bool isEmpty = queue.Empty(); // returns false

        Console.WriteLine($"Pushed 1 and 2.");
        Console.WriteLine($"Peek: {peek1}");
        Console.WriteLine($"Pop: {pop1}");
        Console.WriteLine($"Is queue empty: {isEmpty}");
    }
}

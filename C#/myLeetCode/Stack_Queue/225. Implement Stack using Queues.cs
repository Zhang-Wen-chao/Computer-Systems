// 225. Implement Stack using Queues
// https://leetcode.com/problems/implement-stack-using-queues/

using System.Collections.Generic;

public class MyStack {

    private Queue<int> q1;
    private Queue<int> q2;
    
    public MyStack() {
        q1 = new Queue<int>();
        q2 = new Queue<int>();
    }
    
    public void Push(int x) {
        q2.Enqueue(x);
        while (q1.Count > 0) {
            q2.Enqueue(q1.Dequeue());
        }
        
        var temp = q1;
        q1 = q2;
        q2 = temp;
    }
    
    public int Pop() {
        return q1.Dequeue();
    }
    
    public int Top() {
        return q1.Peek();
    }
    
    public bool Empty() {
        return q1.Count == 0;
    }
}

public class Program {
    public static void Main() {
        MyStack stack = new MyStack();

        stack.Push(1);
        stack.Push(2);
        int top1 = stack.Top();   // returns 2
        int pop1 = stack.Pop();   // returns 2
        bool isEmpty = stack.Empty(); // returns false

        Console.WriteLine($"Pushed 1 and 2.");
        Console.WriteLine($"Top: {top1}");
        Console.WriteLine($"Pop: {pop1}");
        Console.WriteLine($"Is stack empty: {isEmpty}");
    }
}

// 707. Design Linked List
// https://leetcode.com/problems/design-linked-list/
using System;

public class MyLinkedList {
    public class Node {
        public int val;
        public Node next;
        public Node(int _val) {
            val = _val;
            next = null;
        }
    }

    private Node head;
    private int size;

    /** Initialize your data structure here. */
    public MyLinkedList() {
        head = null;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int Get(int index) {
        if (index < 0 || index >= size) return -1;
        
        Node current = head;
        for (int i = 0; i < index; i++) {
            current = current.next;
        }
        return current.val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void AddAtHead(int val) {
        Node newNode = new Node(val);
        newNode.next = head;
        head = newNode;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    public void AddAtTail(int val) {
        if (size == 0) {
            AddAtHead(val);
            return;
        }

        Node newNode = new Node(val);
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void AddAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        if (index == 0) {
            AddAtHead(val);
            return;
        }

        if (index == size) {
            AddAtTail(val);
            return;
        }

        Node newNode = new Node(val);
        Node current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current.next;
        }
        newNode.next = current.next;
        current.next = newNode;
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void DeleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            head = head.next;
            size--;
            return;
        }

        Node current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current.next;
        }
        current.next = current.next.next;
        size--;
    }
}

public class Program {
    public static void Main() {
        MyLinkedList linkedList = new MyLinkedList();
        linkedList.AddAtHead(1);
        linkedList.AddAtTail(3);
        linkedList.AddAtIndex(1, 2);  // linked list becomes 1->2->3
        Console.WriteLine(linkedList.Get(1));            // returns 2
        linkedList.DeleteAtIndex(1);  // now the linked list is 1->3
        Console.WriteLine(linkedList.Get(1));            // returns 3
    }
}

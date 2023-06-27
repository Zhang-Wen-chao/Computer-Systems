// 707. Design Linked List
// https://leetcode.com/problems/design-linked-list/
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class MyLinkedList {
  private:
    ListNode *head;
    int size;

  public:
    MyLinkedList() : head(nullptr), size(0) {}

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        ListNode *curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->val;
    }

    void addAtHead(int val) {
        ListNode *newNode = new ListNode(val, head);
        head = newNode;
        size++;
    }

    void addAtTail(int val) {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode *curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        ListNode *newNode = new ListNode(val);
        ListNode *curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        if (index == 0) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        ListNode *curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        ListNode *temp = curr->next;
        curr->next = temp->next;
        delete temp;
        size--;
    }

    void printLinkedList() {
        ListNode *curr = head;
        while (curr != nullptr) {
            std::cout << curr->val << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    MyLinkedList linkedList;
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2);
    std::cout << linkedList.get(1) << std::endl;
    linkedList.deleteAtIndex(1);
    std::cout << linkedList.get(1) << std::endl;
    linkedList.printLinkedList();

    return 0;
}

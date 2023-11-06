// 707. Design Linked List
// https://leetcode.com/problems/design-linked-list/

#include "LinkedListUtils.hpp"

class MyLinkedList {
private:
    ListNode* head;
public:
    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        ListNode* current = head;
        int i = 0;
        while (current != nullptr && i < index) {
            current = current->next;
            i++;
        }
        if (current == nullptr) {
            return -1;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        ListNode* newNode = new ListNode(val);
        ListNode* current = head;
        int i = 0;
        while (current != nullptr && i < index - 1) {
            current = current->next;
            i++;
        }
        if (current == nullptr) {
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0) {
            return;
        }
        if (index == 0) {
            if (head != nullptr) {
                ListNode* temp = head;
                head = head->next;
                delete temp;
            }
            return;
        }
        ListNode* current = head;
        int i = 0;
        while (current != nullptr && i < index - 1) {
            current = current->next;
            i++;
        }
        if (current == nullptr || current->next == nullptr) {
            return;
        }
        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
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

    return 0;
}

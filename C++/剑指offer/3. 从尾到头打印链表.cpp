#include <iostream>
#include <vector>
#include <stack>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to print elements of a linked list from tail to head
std::vector<int> printListFromTailToHead(ListNode* head) {
    std::stack<int> nodes;
    std::vector<int> result;

    ListNode* node = head;
    while (node != nullptr) {
        nodes.push(node->val);
        node = node->next;
    }

    while (!nodes.empty()) {
        result.push_back(nodes.top());
        nodes.pop();
    }

    return result;
}

// Utility function to print a vector
void printVector(const std::vector<int>& v) {
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    // Call the function and print the result
    std::vector<int> result = printListFromTailToHead(head);
    printVector(result);

    // Free the allocated memory for the linked list
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}

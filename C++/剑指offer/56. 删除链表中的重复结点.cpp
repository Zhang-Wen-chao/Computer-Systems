#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0); // A dummy head for ease of edge cases
        dummy.next = head;
        ListNode* prev = &dummy; // The last node before the sublist of duplicates

        while (head != nullptr) {
            // If it's the end of duplicates sublist
            if (head->next == nullptr || head->val != head->next->val) {
                prev = head;
                head = head->next;
                continue;
            }

            // Skip all duplicates
            while (head->next != nullptr && head->val == head->next->val) {
                head = head->next;
            }

            // Connect the previous non-duplicate with the next non-duplicate
            prev->next = head->next;
            head = head->next; // Move to the next non-duplicate node
        }

        return dummy.next;
    }
};

void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Example usage:
    // List: 1 -> 2 -> 2 -> 3 -> 3 -> 4 -> 5 -> 5
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(2);
    list->next->next->next = new ListNode(3);
    list->next->next->next->next = new ListNode(3);
    list->next->next->next->next->next = new ListNode(4);
    list->next->next->next->next->next->next = new ListNode(5);
    list->next->next->next->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* result = solution.deleteDuplicates(list);

    cout << "List after removing duplicates: ";
    printList(result);

    // Clean up memory
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}

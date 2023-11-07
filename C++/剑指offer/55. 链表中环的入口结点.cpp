#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *EntryNodeOfLoop(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        // Find meeting point
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Cycle detected
                break;
            }
        }

        // Check if there is a cycle
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        // Move slow to Head. Keep fast at Meeting Point. Each are k steps from the Loop Start.
        // If they move at the same pace, they must meet at Loop Start.
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Both now point to the start of the loop.
        return fast;
    }
};

// Helper function to create a cycle in the list for demonstration purposes
void createCycle(ListNode *head, int pos) {
    ListNode *temp = head;
    ListNode *cycleNode = nullptr;
    int index = 0;
    while (temp->next != nullptr) {
        if (index == pos) {
            cycleNode = temp;
        }
        temp = temp->next;
        index++;
    }
    temp->next = cycleNode; // Creating a cycle
}

int main() {
    // Create a linked list for demonstration: 1->2->3->4->5->3...
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create a cycle in the list
    createCycle(head, 2);

    Solution solution;
    ListNode *entryNode = solution.EntryNodeOfLoop(head);
    if (entryNode) {
        cout << "The entry node of the loop is: " << entryNode->val << endl;
    } else {
        cout << "There is no cycle in the list." << endl;
    }

    // Cleanup, be careful not to enter infinite loop due to cycle
    // Normally you'd need to break the cycle before deleting nodes to avoid an infinite loop
    // For this demonstration, we'll leak the list to avoid complex cycle handling
    // In a real-world scenario, you'd handle the memory cleanup properly

    return 0;
}

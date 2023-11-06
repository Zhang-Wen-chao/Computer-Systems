#include <iostream>
#include <vector>
#include <algorithm> // 用于std::reverse

// 链表节点的定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 使用std::reverse从尾到头打印链表
std::vector<int> printListFromTailToHead(ListNode* head) {
    std::vector<int> result;
    ListNode* current = head; // 使用临时指针遍历链表
    while(current != nullptr){
        result.push_back(current->val);
        current = current->next;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    // 创建链表 1->2->3
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    // 打印链表
    std::vector<int> result = printListFromTailToHead(head);
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 清理链表内存
    ListNode *current = head;
    while (current != nullptr) {
        ListNode *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}

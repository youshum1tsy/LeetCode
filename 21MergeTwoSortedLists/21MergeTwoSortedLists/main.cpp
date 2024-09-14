#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createNode(int x) {
    return new ListNode(x);
}

ListNode* createLinkedList(std::vector<int> list) {
    if (list.empty()) {
        return nullptr;
    }

    ListNode* head = createNode(list[0]);
    ListNode* current = head;

    for (int i = 1; i < list.size(); i++) {
        current->next = createNode(list[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
}

void deleteLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
       
        ListNode* mergedHead = nullptr;
        if (list1->val <= list2->val) {
            mergedHead = list1;
            list1 = list1->next;
        }
        else {
            mergedHead = list2;
            list2 = list2->next;
        }

        ListNode* mergedTail = mergedHead;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                mergedTail->next = list1;
                list1 = list1->next;
            }
            else {
                mergedTail->next = list2;
                list2 = list2->next;
            }
            mergedTail = mergedTail->next;
        }

        if (list1 != nullptr)
            mergedTail->next = list1;
        if (list2 != nullptr)
            mergedTail->next = list2;

        return mergedHead;
	}
};

int main() {
    std::vector<int> values1 = { 1, 2, 4 };
    std::vector<int> values2 = { 1, 3, 4 };

    ListNode* list1 = createLinkedList(values1);
    ListNode* list2 = createLinkedList(values2);

    std::cout << "\nList 1: ";
    printLinkedList(list1);

    std::cout << "\nList 2: ";
    printLinkedList(list2);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    std::cout << "\nMerged List: ";
    printLinkedList(mergedList);
    deleteLinkedList(mergedList);

    return 0;
}
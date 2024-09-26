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

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) {
			return head;
		}
		ListNode* temp = head;
		ListNode* next = temp->next;
		if (!next) {
			return temp;
		}
		while (temp != nullptr && next != nullptr) {
			if (temp->val == next->val) {
				temp->next = next->next;
				next = temp->next;
			}
			else {
				temp = next;
				next = next->next;
			}
		}
		return head;
	}
};

int main() {
	std::vector<int> values = { 1, 1, 2, 2, 4 };

	ListNode* list = createLinkedList(values);

	std::cout << "List: ";
	printLinkedList(list);

	Solution solution;
	ListNode* uniqueList = solution.deleteDuplicates(list);

	std::cout << "\nunique List: ";
	printLinkedList(uniqueList);

}
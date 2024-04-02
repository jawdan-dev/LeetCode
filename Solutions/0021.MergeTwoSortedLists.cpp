/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		// Check for empty lists.
		if (list1 == nullptr && list2 == nullptr) return nullptr;
		if (list1 == nullptr) return list2;
		if (list2 == nullptr) return list1;

		// Mergin' time.
		ListNode* root = nullptr, * activeNode = nullptr;
		ListNode* left = list1, * right = list2;

		// Merge.
		while (left != nullptr && right != nullptr) {
			if (left->val < right->val) {
				if (activeNode == nullptr) {
					// Initialize root.
					root = left;
					activeNode = left;
				} else {
					// Merge left.
					activeNode->next = left;
					activeNode = activeNode->next;
				}

				// Update left.
				left = left->next;
			} else {
				if (activeNode == nullptr) {
					// Initialize root.
					root = right;
					activeNode = right;
				} else {
					// Merge right.
					activeNode->next = right;
					activeNode = activeNode->next;
				}

				// Update right.
				right = right->next;
			}
		}

		// Merge remaining.
		if (left != nullptr) activeNode->next = left;
		if (right != nullptr) activeNode->next = right;

		return root;
	}
};
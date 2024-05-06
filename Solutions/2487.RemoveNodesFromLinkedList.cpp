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
	ListNode* removeNodes(ListNode* head) {
		// Ignore if tail.
		if (head->next == nullptr)
			return head;

		// Recurse.
		ListNode* highest = removeNodes(head->next);

		// Compare against highest.
		if (head->val < highest->val)
			// Greater than highest -> gets removed (ignored).
			return highest;

		// Less than highest -> safe to stay.
		head->next = highest;
		return head;
	}
};
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
	const int doubleLink(ListNode* head) {
		const int additional = head->next != nullptr ? doubleLink(head->next) : 0;
		const bool carry = head->val >= 5;
		head->val = (carry ? (head->val * 2) - 10 : (head->val * 2)) + additional;
		return carry ? 1 : 0;
	}

	ListNode* doubleIt(ListNode* head) {
		const int carry = doubleLink(head);
		if (carry) head = new ListNode(carry, head);
		return head;
	}
};
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// Node storage.
		// NOTE: Memory leak is intention due to the environment of the problem.
		ListNode* root = new ListNode();

		// Iterate nodes.
		ListNode* activeNode = root;
		int carry = 0;
		while (l1 || l2 || carry) {
			// Check for early exit.
			if (carry == 0 && (!l1 || !l2)) {
				if (!l1 && l2) {
					activeNode->next = l2;
					break;
				}
				if (l1 && !l2) {
					activeNode->next = l1;
					break;
				}
			}

			// Get node addition total.
			const int total = carry +
				(l1 ? l1->val : 0) +
				(l2 ? l2->val : 0);

			// Calculate carry.
			carry = total / 10;

			// Add node.
			activeNode->next = new ListNode(total % 10);
			activeNode = activeNode->next;

			// Increment nodes.
			l1 = l1 ? l1->next : nullptr;
			l2 = l2 ? l2->next : nullptr;
		}

		// Return result.
		return root->next;
	}
};
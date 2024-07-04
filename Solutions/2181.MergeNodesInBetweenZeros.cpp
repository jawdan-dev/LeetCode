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
	ListNode* mergeNodes(ListNode* head) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		ListNode
			* mergeLast = nullptr,
			* mergeOrigin = nullptr,
			* activeNode = head;

		while (activeNode != nullptr) {
			// Check for zero.
			if (activeNode->val == 0) {
				// Update list next.
				if (mergeOrigin != nullptr)
					mergeOrigin->next = activeNode;

				// Traverse origin.
				mergeLast = mergeOrigin;
				mergeOrigin = activeNode;
			} else {
				// Increment merged value.
				mergeOrigin->val += activeNode->val;
			}

			// Iterate.
			activeNode = activeNode->next;
		}

		// Remove last 0.
		mergeLast->next = nullptr;

		// New merged list should be stored in original head.
		return head;
	}
};
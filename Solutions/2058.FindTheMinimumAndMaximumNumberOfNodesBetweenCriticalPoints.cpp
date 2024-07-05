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
	vector<int> nodesBetweenCriticalPoints(ListNode* head) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Too small for critical points.
		if (head->next == nullptr || head->next->next == nullptr) return { -1, -1 };

		// Setup search.
		ListNode
			* left = head,
			* middle = left->next,
			* right = middle->next;

		// Search.
		int minDist = INT_MAX, maxDist = -1;
		int activeIndex = 1, lastCriticalPoint = -1, firstCriticalPoint = -1;
		while (right != nullptr) {
			// Check for critical point.
			if ((left->val > middle->val && middle->val < right->val) ||
				(left->val < middle->val && middle->val > right->val)) {

				// Update distances.
				if (lastCriticalPoint != -1)
					minDist = min(minDist, activeIndex - lastCriticalPoint);
				if (firstCriticalPoint != -1)
					maxDist = max(maxDist, activeIndex - firstCriticalPoint);

				// Update last critical point.
				lastCriticalPoint = activeIndex;
				// Update first critical point.
				if (firstCriticalPoint == -1)
					firstCriticalPoint = activeIndex;
			}

			// Traverse.
			left = middle;
			middle = right;
			right = middle->next;
			activeIndex++;
		}


		return { minDist == INT_MAX ? -1 : minDist, maxDist };
	}
};
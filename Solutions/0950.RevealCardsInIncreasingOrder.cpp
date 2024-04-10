class Solution {
public:
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		// Sort into ascending order.
		sort(deck.begin(), deck.end());

		// Create index queue.
		queue<int> indexOrder;
		for (int i = 0; i < deck.size(); i++)
			indexOrder.push(i);

		// Sort.
		vector<int> expectedOrder(indexOrder.size());
		int indexOffset = 0;
		while (!indexOrder.empty()) {
			// Add first to list.
			expectedOrder[indexOrder.front()] = deck[indexOffset++];
			indexOrder.pop();
			if (indexOrder.empty()) continue;

			// Move second to back.
			indexOrder.push(indexOrder.front());
			indexOrder.pop();
		}

		return expectedOrder;
	}
};
class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int groupSize) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Get sorted card counts.
		map<int, int> cardCounts;
		for (int i = 0; i < hand.size(); i++) {
			auto it = cardCounts.find(hand[i]);
			if (it == cardCounts.end()) {
				cardCounts.emplace(hand[i], 1);
			} else {
				it->second++;
			}
		}

		vector<map<int, int>::iterator> cards(groupSize);
		while (!cardCounts.empty()) {
			// Get cards in group.
			cards[0] = cardCounts.begin();
			for (int i = 1; i < groupSize; i++) {
				// Find next card in group.
				cards[i] = cardCounts.find(cards[i - 1]->first + 1);
				// Check if card valid.
				if (cards[i] == cardCounts.end()) return false;
			}

			// Update card count and remove if no more remain.
			for (int i = 0; i < groupSize; i++) {
				cards[i]->second--;
				if (cards[i]->second <= 0) cardCounts.erase(cards[i]);
			}
		}

		return true;
	}
};
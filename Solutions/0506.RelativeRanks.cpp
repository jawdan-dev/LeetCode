class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& score) {
		// Find medal order.
		map<int, int> scoreOrder;
		for (int i = 0; i < score.size(); i++) {
			scoreOrder.emplace(score[i], i);
		}

		// Create medals strings.
		vector<string> medals(score.size());
		int place = 1;
		for (auto it = scoreOrder.rbegin(); it != scoreOrder.rend(); it++, place++) {
			// Set place string.
			medals[it->second] =
				(place > 3 ? to_string(place) :
				(place == 3 ? "Bronze Medal" :
					(place == 2 ? "Silver Medal" :
						"Gold Medal")));
		}
		return medals;
	}
};
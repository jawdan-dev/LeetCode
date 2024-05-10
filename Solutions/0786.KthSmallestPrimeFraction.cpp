class Solution {
public:
	vector<int>* arrValues;
	set<pair<int, int>> usedIndices;
	map<double, pair<int, int>> activeIndices;
	int n;
	inline void addActiveIndex(const pair<int, int>& indices) {
		if (indices.first + indices.second >= n) return;
		// Ignore if indices already used.
		if (usedIndices.find(indices) != usedIndices.end()) return;

		// Add to indices.
		activeIndices.emplace((double)(*arrValues)[indices.first] / (double)(*arrValues)[n - indices.second], indices);
		usedIndices.emplace(indices);
	}

	vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
		// Initialize malarkey.
		n = arr.size() - 1;
		arrValues = &arr;
		usedIndices = set<pair<int, int>>();
		activeIndices = map<double, pair<int, int>>();
		addActiveIndex(pair<int, int>(0, 0));

		while (!activeIndices.empty() && k > 1) {
			auto it = activeIndices.begin();

			addActiveIndex(pair<int, int>(it->second.first + 1, it->second.second));
			addActiveIndex(pair<int, int>(it->second.first, it->second.second + 1));

			activeIndices.erase(it);
			k--;
		}

		const auto target = activeIndices.begin()->second;
		return { arr[target.first], arr[n - target.second] };

		// 1 / 5   1 / 3   1 / 2
		// 2 / 5   2 / 3
		// 3 / 5

		// 1 / 5
		// 1 / 3
		// 2 / 5 <
		// 1 / 2
		// 3 / 5
		// 2 / 3
	}
};
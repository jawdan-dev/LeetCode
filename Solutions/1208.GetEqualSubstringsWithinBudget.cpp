class Solution {
public:
	int equalSubstring(string s, string t, int maxCost) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Pre-calculate costs.
		const int n = min(s.size(), t.size());
		vector<int> costs(n, 0);
		for (int i = 0; i < n; i++) costs[i] = abs(s[i] - t[i]);

		// Calculate the max length.
		int maxLength = 0, workingCost = 0, left = 0;
		for (int right = 0; right < n; right++) {
			// Add cost.
			workingCost += costs[right];

			// Remove cost from front.
			while (workingCost > maxCost) {
				workingCost -= costs[left];
				left++;
			}

			// Update the max length.
			maxLength = max(maxLength, (right - left) + 1);
		}
		return maxLength;
	}
};
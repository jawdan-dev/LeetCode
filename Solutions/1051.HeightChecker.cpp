class Solution {
public:
	int heightChecker(vector<int>& heights) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = heights.size();

		// Create expected.
		vector<int> expected(heights.begin(), heights.end());
		sort(expected.begin(), expected.end());

		// Count difference.
		int differenceCount = 0;
		for (int i = 0; i < n; i++) {
			differenceCount += (heights[i] != expected[i]) ? 1 : 0;
		}
		return differenceCount;
	}
};
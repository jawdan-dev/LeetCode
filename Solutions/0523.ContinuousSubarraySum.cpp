class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Early exit.
		if (k == 0) return true;

		// Calculation variables.
		unordered_map<int, int> activeRemainders;
		activeRemainders.emplace(0, -1);
		int totalSum = 0;

		// Find valid case.
		const int n = nums.size();
		for (int i = 0; i < n; i++) {
			// Update sum.
			totalSum += nums[i];

			// Get remainder.
			const int remainder = totalSum % k;

			// Check if remainder exists.
			const auto it = activeRemainders.find(remainder);
			if (it == activeRemainders.end()) {
				activeRemainders.emplace(remainder, i);
				continue;
			}

			// Check if remainder is part of a valid subset.
			if ((i - it->second) > 1) return true;
		}

		// No valid case found.
		return false;
	}
};
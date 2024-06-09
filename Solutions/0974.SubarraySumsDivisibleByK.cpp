class Solution {
public:
	int subarraysDivByK(vector<int>& nums, int k) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		unordered_map<int, int> activeRemainders;
		activeRemainders.emplace(0, 1);
		int totalSum = 0;

		// Find valid count.
		int validSubarrays = 0;
		const int n = nums.size();
		for (int i = 0; i < n; i++) {
			// Update sum.
			totalSum += nums[i];

			// Get remainder.
			int remainder = totalSum % k;
			while (remainder < 0) remainder += k;

			// Check if remainder exists.
			const auto it = activeRemainders.find(remainder);
			if (it == activeRemainders.end()) {
				// Add index to collection.
				activeRemainders.emplace(remainder, 1);
				continue;
			}

			// Valid subarray combination found.

			// Update count.
			validSubarrays += it->second;
			// Update tracked count.
			it->second++;
		}

		// No valid case found.
		return validSubarrays;
	}
};
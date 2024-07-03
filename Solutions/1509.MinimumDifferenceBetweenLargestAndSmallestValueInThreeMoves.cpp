class Solution {
public:
	int minDifference(vector<int>& nums) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Early exit.
		constexpr int possibleChanges = 3;
		if (nums.size() <= possibleChanges + 1) return 0;

		// Sort values.
		sort(nums.begin(), nums.end());

		// Calculation variables.
		const int n = nums.size();
		const int offset = n - (possibleChanges + 1);

		// Try all permutations.
		int minDif = nums[n - 1] - nums[0];
		for (int i = 0; i <= possibleChanges; i++)
			minDif = min(minDif, nums[offset + i] - nums[i]);

		// Return min difference.
		return minDif;
	}
};
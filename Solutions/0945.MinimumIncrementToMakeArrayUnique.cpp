class Solution {
public:
	int minIncrementForUnique(vector<int>& nums) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Sort for fun.
		sort(nums.begin(), nums.end());

		// Get move count.
		int moveCount = 0;
		const int n = nums.size();
		for (int i = 1; i < n; i++) {
			// Ignore all good ones.
			if (nums[i] > nums[i - 1]) continue;

			const int moveVal = nums[i - 1] + 1;
			// Update move count.
			moveCount += moveVal - nums[i];
			// Update the value.
			nums[i] = moveVal;
		}
		return moveCount;
	}
};
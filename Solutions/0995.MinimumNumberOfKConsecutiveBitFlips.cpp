class Solution {
public:
	int minKBitFlips(vector<int>& nums, int k) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = nums.size(), nmk = n - k;

		// Find total of flips needed.
		int totalFlips = 0, flipCarry = 0;
		for (int i = 0; i < n; i++) {
			// Get num state (relative to flips).
			const int numState = (nums[i] + flipCarry) % 2;

			// Handle num case.
			if (numState == 0) {
				// Cannot flip outside bounds of array.
				if (i > nmk) return -1;

				// Update flip counts.
				totalFlips++;
				flipCarry++;

				// Make sure the value gets 'uncarried'.
				nums[i] = -1;
			}

			// Remove left-most window element from flip carry.
			if (i + 1 >= k)
				flipCarry -= nums[i - k + 1] < 0 ? 1 : 0;
		}
		return totalFlips;
	}
};
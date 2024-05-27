class Solution {
public:
	int specialArray(vector<int>& nums) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Sort.
		sort(nums.begin(), nums.end());

		// Check for early exit.
		const int n = nums.size();
		if (nums[0] >= n) return n;

		// Blargin.
		for (int i = 1; i < n; i++) {
			const int count = n - i;
			if (nums[count - 1] < i && i <= nums[count]) return i;
		}

		// Value not found.
		return -1;
	}
};
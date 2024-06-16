class Solution {
public:
	int minPatches(vector<int>& nums, int n) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Find patches.
		int patches = 0;
		long long target = 1;
		for (int i = 0; target <= n;) {
			// Check if patch needs to be made.
			if (i >= nums.size() || target < nums[i]) {
				// Update patch count.
				patches++;
				// Move up target.
				target += target;
			} else {
				// All is good, move onto next num.
				target += nums[i];
				i++;
			}
		}

		return patches;
	}
};
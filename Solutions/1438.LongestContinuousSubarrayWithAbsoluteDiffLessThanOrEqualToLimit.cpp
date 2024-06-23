class Solution {
public:
	int longestSubarray(vector<int>& nums, int limit) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = nums.size();

		// Search for longest subarray using window approach.
		multiset<int> activeWindow;
		int windowLeft = 0, longestSubarray = 0;
		for (int i = 0; i < n; i++) {
			// Add active location to array.
			activeWindow.emplace(nums[i]);

			// Remove left-most conflicting members.
			while (
				!activeWindow.empty() &&
				windowLeft <= i &&
				(*activeWindow.rbegin() - *activeWindow.begin()) > limit
			) //
				activeWindow.erase(activeWindow.find(nums[windowLeft++]));

			// Update longest.
			longestSubarray = max(longestSubarray, (int)activeWindow.size());
		}
		return longestSubarray;
	}
};
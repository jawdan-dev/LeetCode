class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = nums.size();
		vector<int> subCounts(n + 1, 0);
		subCounts[0] = 1;

		// Get subarray count.
		int totalCount = 0, workingSubIndex = 0;
		for (int i = 0; i < n; i++) {
			// Increment index on odd value.
			workingSubIndex += nums[i] & 0b1;

			// Add to total.
			if (workingSubIndex >= k)
				totalCount += subCounts[workingSubIndex - k];

			// Update count.
			subCounts[workingSubIndex]++;
		}
		// Return count.
		return totalCount;
	}
};
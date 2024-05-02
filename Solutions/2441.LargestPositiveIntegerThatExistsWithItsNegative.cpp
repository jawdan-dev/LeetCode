class Solution {
public:
	int findMaxK(vector<int>& nums) {
		// Sort.
		sort(nums.begin(), nums.end());

		// Two-pointers.
		int i = 0, j = nums.size() - 1;
		while (i < j) {
			// Get k.
			const int nk = -nums[i], k = nums[j];

			// Check case.
			if (nk == k) return k;
			else if (nk < k) j--;
			else i++;
		}

		// K not found.
		return -1;
	}
};
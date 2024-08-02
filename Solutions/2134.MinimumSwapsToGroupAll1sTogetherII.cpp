class Solution {
public:
	int minSwaps(vector<int>& nums) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = nums.size();

		// Get one count.
		int oneCount = 0;
		for (int i = 0; i < n; i++)
			oneCount += nums[i];

		// Early exit if already complete.
		if (oneCount == n || oneCount == 0)
			return 0;

		// Initialize window.
		int zeroCount = 0, end;
		for (end = 0; end < oneCount; end++)
			zeroCount += 1 - nums[end];

		// Find best window total.
		int total = n;
		for (int i = 0; i < n; end = (end + 1) % n, i++) {
			zeroCount += nums[i] - nums[end];
			total = min(total, zeroCount);
		}
		return total;
	}
};
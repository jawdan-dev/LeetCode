class Solution {
public:
	void sortColors(vector<int>& nums) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Get color counts.
		const int n = nums.size();
		int colorCounts[3] { 0, 0, 0 };
		for (int i = 0; i < n; i++)
			colorCounts[nums[i]]++;

		// 'Sort'.
		int workingIndex = 0;
		for (int i = 0; i < sizeof(colorCounts) / sizeof(*colorCounts); i++)
			for (int j = 0; j < colorCounts[i]; j++)
				nums[workingIndex++] = i;
	}
};
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Setup used value map.
		int usedValues[1001];
		memset(usedValues, 0, sizeof(usedValues));
		for (int i : nums1)
			usedValues[i]++;

		// Find all common values.
		vector<int> result;
		result.reserve(nums2.size());
		for (int i : nums2) {
			if (usedValues[i] <= 0) continue;
			// Add to result.
			usedValues[i]--;
			result.emplace_back(i);
		}
		return result;
	}
};
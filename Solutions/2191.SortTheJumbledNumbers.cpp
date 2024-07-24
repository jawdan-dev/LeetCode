class Solution {
public:
	vector<int>* m_mapping;
	const int getRemappedValue(int value) {
		// Handle edge case.
		if (value == 0) return (*m_mapping)[0];

		int remapped = 0;
		for (int power = 1; value > 0; power *= 10) {
			// Get active digit.
			const int m = value % 10;

			// Add remmaped digit to total.
			remapped += (*m_mapping)[m] * power;

			// Step digit.
			value /= 10;
		}
		return remapped;
	}

	vector<int>& sortJumbled(vector<int>& mapping, vector<int>& nums) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Setup calculation variables.
		const int n = nums.size();
		m_mapping = &mapping;

		// Create mapping.
		vector<tuple<int, int, int>> mappedValues(n);
		for (int i = 0; i < n; i++)
			mappedValues[i] = make_tuple(getRemappedValue(nums[i]), i, nums[i]);

		// Sort mapped values.
		sort(mappedValues.begin(), mappedValues.end());

		// Update nums array.
		for (int i = 0; i < n; i++)
			nums[i] = get<2>(mappedValues[i]);

		return nums;
	}
};
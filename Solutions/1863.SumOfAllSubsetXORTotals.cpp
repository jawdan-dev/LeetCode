class Solution {
public:
	int m_total, m_n;
	vector<int>* m_nums;

	const int xorSubset(const int offsetStart, const int setTotal) {
		// Check if in range.
		if (offsetStart >= m_n) return setTotal;

		// Total subsets.
		return
			// Recurse subset with self.
			xorSubset(offsetStart + 1, setTotal ^ (*m_nums)[offsetStart]) +
			// Recurse subset without self.
			xorSubset(offsetStart + 1, setTotal);
	}

	int subsetXORSum(vector<int>& nums) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Setup calculation variables.
		m_n = nums.size();
		m_nums = &nums;

		// Return total.
		return xorSubset(0, 0);
	}
};
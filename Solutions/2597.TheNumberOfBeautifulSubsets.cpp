class Solution {
public:
	vector<int>* m_nums;
	int m_n, m_k;
	unordered_map<int, int> m_workingSet;
	int m_totalSubsets;

	void calculateSubsets(const int offset) {
		if (offset >= m_n) {
			// Count set as beautiful.
			if (!m_workingSet.empty()) m_totalSubsets++;
			// End of the line, pal.
			return;
		}

		// Process non-derived subsets.
		calculateSubsets(offset + 1);

		// Get key value.
		const int key = (*m_nums)[offset];

		// Check if beautiful.
		if (m_workingSet.find(key + m_k) != m_workingSet.end() ||
			m_workingSet.find(key - m_k) != m_workingSet.end()) {
			// Not beautiful.
			return;
		}

		// Update working set.
		auto it = m_workingSet.find(key);
		if (it == m_workingSet.end()) {
			// Add to working set.
			it = m_workingSet.emplace(key, 1).first;
		} else {
			// Update working set count.
			it->second++;
		}

		// Calculate derived subsets.
		calculateSubsets(offset + 1);

		// Update working set count.
		if (--it->second <= 0)
			// Remove from working set.
			m_workingSet.erase(it);
	}

	int beautifulSubsets(vector<int>& nums, int k) {
		// Speed thingies.
		// ios_base::sync_with_stdio(false);
		// cin.tie(nullptr);
		// cout.tie(nullptr);

		// Calculation variables.
		m_k = k;
		m_nums = &nums;
		m_n = m_nums->size();
		m_totalSubsets = 0;

		// Calculate total subsets.
		calculateSubsets(0);
		return m_totalSubsets;
	}
};
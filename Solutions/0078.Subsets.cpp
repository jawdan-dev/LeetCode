class Solution {
public:
	vector<vector<int>> m_subsets;
	vector<int> m_workingSet;
	int m_n;
	vector<int>* m_nums;

	void addSubset(const int offset) {
		if (offset >= m_n) {
			// Add working set to list.
			m_subsets.emplace_back(m_workingSet);
			return;
		}

		// Process unrelated subsets.
		addSubset(offset + 1);

		// Add value to working set (Unique by logic).
		m_workingSet.emplace_back((*m_nums)[offset]);

		// Process subsets.
		addSubset(offset + 1);

		// Reset working set.
		m_workingSet.pop_back();
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		m_nums = &nums;
		m_n = m_nums->size();

		// Get all subsets.
		addSubset(0);
		return m_subsets;
	}
};
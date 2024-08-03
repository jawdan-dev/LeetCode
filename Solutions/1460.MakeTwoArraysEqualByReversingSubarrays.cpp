class Solution {
public:
	int m_count[1001];

	bool canBeEqual(vector<int>& target, vector<int>& arr) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Initialize values.
		memset(m_count, 0, sizeof(m_count));

		// Count values.
		const int n = min(target.size(), arr.size());
		for (int i = 0; i < n; i++) {
			m_count[target[i]]++;
			m_count[arr[i]]--;
		}

		// Look for any non-zero counts.
		int found = 0;
		for (int i = 1; i < 1000 && found == 0; i++)
			found = m_count[i];

		// Check if non-zero found.
		return found == 0;
	}
};
class Solution {
public:
	vector<vector<int>>* m_events;

	int maxValue(vector<vector<int>>& events, int k) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		struct {
			bool operator()(vector<int>& a, vector<int>& b) const {
				if (a[1] != b[1])
					return a[1] < b[1];
				if (a[0] != b[0])
					return a[0] < b[0];
				return a[2] < b[2];
			}
		} sortByStartDay;
		std::sort(events.begin(), events.end(), sortByStartDay);
		m_events = &events;

		const int size = events.size();
		vector<vector<int>> dp(size + 1, vector<int>(k + 1, 0));

		for (int i = 0; i < size; i++) {
			const int previousValid = findPreviousValid(i);
			for (int j = 0; j < k; j++) {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[previousValid + 1][j] + events[i][2]);
			}
		}
		return dp[size][k];
	}

	const int findPreviousValid(const int index) {
		const int start = (*m_events)[index][0];
		int prev = index - 1;
		while (prev >= 0 && (*m_events)[prev][1] >= start)
			prev--;
		return prev;
	}
};
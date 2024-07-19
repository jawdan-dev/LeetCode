class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int m = matrix.size(), n = matrix[0].size();

		// Calculate min + max values.
		vector<int>
			minRows(m, INT_MAX),
			maxColumns(n, 0);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				minRows[i] = min(minRows[i], matrix[i][j]);
				maxColumns[j] = max(maxColumns[j], matrix[i][j]);
			}
		}

		// Find lucky numbers.
		vector<int> luckyNumbers;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (minRows[i] == maxColumns[j])
					luckyNumbers.emplace_back(minRows[i]);
		return luckyNumbers;
	}
};
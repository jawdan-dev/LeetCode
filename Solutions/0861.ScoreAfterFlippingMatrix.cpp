class Solution {
public:
	int matrixScore(vector<vector<int>>& grid) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Fun variables...
		const int n = grid.size(), m = grid[0].size();
		int activeBit = 1 << (m - 1);

		// Start with first columns as set.
		int total = activeBit * n, set;
		// Columns tipping time. (Ignore fist column -> already in total)
		for (int i = 1; i < m; i++) {
			// Shift active bit.
			activeBit >>= 1;

			// Get the total rows with active bits.
			set = 0;
			for (int j = 0; j < n; j++)
				// NOTE: The first column flip is compared against.
				if (grid[j][i] == grid[j][0])
					set++;

			// Use the max of non-flipped vs flipped column towards total.
			total += max(set, n - set) * activeBit;
		}
		return total;
	}
};
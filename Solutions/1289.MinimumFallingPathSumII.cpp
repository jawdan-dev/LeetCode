class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& grid) {
		// Get n.
		const int n = grid.size();

		// Fun.
		for (int i = 1; i < n; i++) {
			// Calculation storage.
			int min1 = INT_MAX,
				min2 = INT_MAX,
				index = -1;

			// Find lowest 2 minimums.
			for (int j = 0; j < n; j++) {
				if (grid[i - 1][j] < min1) {
					min2 = min1;
					min1 = grid[i - 1][j];
					index = j;
				} else if (grid[i - 1][j] < min2 && index != j) {
					min2 = grid[i - 1][j];
				}
			}

			// Update bottom row of active grid with path costs.
			for (int j = 0; j < n; j++)
				grid[i][j] += (j != index ? min1 : min2);
		}

		// Return min value in lowest row of grid.
		int minValue = grid[n - 1][0];
		for (int i = 1; i < n; i++)
			minValue = min(minValue, grid[n - 1][i]);
		return minValue;
	}
};
class Solution {
public:
	vector<vector<int>>* s_grid;
	bool s_visitedCells[15][15];

	int getMaximumGoldRecursive(const int x, const int y) {
		// Make sure its in bounds.
		if (x < 0 || y < 0 || x >= (*s_grid).size() || y >= (*s_grid)[x].size()) return 0;

		// Ignore if gold value is 0.
		if ((*s_grid)[x][y] <= 0) return 0;

		// Set visited state.
		if (s_visitedCells[x][y]) return 0;
		s_visitedCells[x][y] = true;

		// Visit neighbours.
		static const int checks[][2] = {
			{ -1, +0 }, { +1, +0 },
			{ +0, -1 }, { +0, +1 },
		};
		int maxGold = 0;
		for (int i = 0; i < sizeof(checks) / sizeof(*checks); i++) {
			maxGold = max(maxGold, getMaximumGoldRecursive(x + checks[i][0], y + checks[i][1]));
		}

		// Reset visited status.
		s_visitedCells[x][y] = false;

		// Return best gold found inc self.
		return maxGold + (*s_grid)[x][y];
	}

	int getMaximumGold(vector<vector<int>>& grid) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Recursion setup.
		s_grid = &grid;
		memset(s_visitedCells, false, sizeof(s_visitedCells));

		// Recurse grid.
		int maxGold = 0;
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[i].size(); j++)
				if (grid[i][j] != 0)
					maxGold = max(maxGold, getMaximumGoldRecursive(i, j));
		return maxGold;
	}
};
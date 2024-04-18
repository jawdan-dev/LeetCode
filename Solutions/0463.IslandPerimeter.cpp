class Solution {
public:
	inline int isWater(vector<vector<int>>& grid, const int x, const int y) {
		if (x < 0 || y < 0 || y >= grid.size() || x >= grid[y].size())
			return true;
		return grid[y][x] == 0;
	}

	int islandPerimeter(vector<vector<int>>& grid) {
		constexpr int checks[][2] = {
			{ -1, 0 },
			{ +1, 0 },
			{ 0, -1 },
			{ 0, +1 },
		};

		int totalPerimeter = 0;
		for (int y = 0; y < grid.size(); y++) {
			for (int x = 0; x < grid[y].size(); x++) {
				if (grid[y][x] == 0) continue;

				for (int i = 0; i < sizeof(checks) / sizeof(*checks); i++)
					totalPerimeter += isWater(grid, x + checks[i][0], y + checks[i][1]) ? 1 : 0;
			}
		}

		return totalPerimeter;
	}
};
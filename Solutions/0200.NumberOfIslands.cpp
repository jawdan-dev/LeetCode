class Solution {
public:
	void expandIsland(vector<vector<char>>& grid, int x, int y) {
		// Check if valid island.
		if (x < 0 || y < 0 || y >= grid.size() || x >= grid[y].size() || grid[y][x] != '1') return;

		// Update grid data, as to not repeat.
		grid[y][x] = '2';


		// Expand in all directions.
		static const int checks[][2] = {
			{ -1, 0 }, { +1, 0 },
			{ 0, -1 }, { 0, +1 },
		};
		for (int i = 0; i < sizeof(checks) / sizeof(*checks); i++)
			expandIsland(grid, x + checks[i][0], y + checks[i][1]);
	}

	int numIslands(vector<vector<char>>& grid) {
		// Get island count.
		int islandCount = 0;
		for (int y = 0; y < grid.size(); y++) {
			for (int x = 0; x < grid[y].size(); x++) {
				// Ignore if not land.
				if (grid[y][x] != '1') continue;

				// Expand island.
				expandIsland(grid, x, y);
				islandCount++;
			}
		}

		return islandCount;
	}
};
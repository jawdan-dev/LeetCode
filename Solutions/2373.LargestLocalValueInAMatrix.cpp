class Solution {
public:
	vector<vector<int>> convolute(const vector<vector<int>>& grid) {
		constexpr int convolutionFactor = 3;
		const int n = grid.size() - (convolutionFactor - 1);
		vector<vector<int>> newGrid(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < convolutionFactor; k++) {
					for (int l = 0; l < convolutionFactor; l++) {
						newGrid[i][j] = max(newGrid[i][j], grid[i + k][j + l]);
					}
				}
			}
		}

		return newGrid;
	}

	vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
		return convolute(grid);
	}
};
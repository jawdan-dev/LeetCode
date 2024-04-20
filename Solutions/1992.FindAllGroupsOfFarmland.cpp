class Solution {
public:
	vector<vector<int>> findFarmland(vector<vector<int>>& land) {
		// Find farmland.
		vector<vector<int>> foundFarmland;
		for (int y = 0; y < land.size(); y++) {
			for (int x = 0; x < land[y].size(); x++) {
				if (land[y][x] == 0) continue;

				// Move x to end of land.
				const int startX = x;
				while (x < land[y].size() && land[y][x] != 0) x++;
				x--;

				// Move temp y to bottom of land.
				int endY = y;
				while (endY < land.size() && land[endY][x] != 0) endY++;
				endY--;

				// Push found land.
				foundFarmland.push_back({ y, startX, endY, x });

				// Clear area.
				for (int ay = y + 1; ay <= endY; ay++)
					for (int ax = startX; ax <= x; ax++)
						land[ay][ax] = 0;
			}
		}

		// Return found farmland.
		return foundFarmland;
	}
};
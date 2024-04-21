class Solution {
public:
	bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
		// Preprocess edges.
		set<pair<int, int>> edgePairs;
		for (int i = 0; i < edges.size(); i++)
			edgePairs.emplace(edges[i][0], edges[i][1]);

		// Find valid path.
		set<int> newPoints, activePoints;
		activePoints.emplace(source);
		while (!activePoints.empty()) {
			for (const int point : activePoints) {
				// Check if path found.
				if (point == destination) return true;

				// Find matching edges.
				for (auto it = edgePairs.begin(); it != edgePairs.end(); ) {
					if (it->first == point) {
						// Add edge point to new points + remove edge from list.
						newPoints.emplace(it->second);
						it = edgePairs.erase(it);
					} else if (it->second == point) {
						// Add edge point to new points + remove edge from list.
						newPoints.emplace(it->first);
						it = edgePairs.erase(it);
					} else {
						it++;
					}
				}
			}
			// Update active points.
			activePoints = newPoints;
			newPoints.clear();
		}

		// Found not found.
		return false;
	}
};
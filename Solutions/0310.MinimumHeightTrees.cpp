class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		// Place edges into set.
		set<pair<int, int>> binEdges;
		for (int i = 0; i < edges.size(); i++)
			binEdges.emplace(edges[i][0], edges[i][1]);

		// Calculate node totals + edges.
		vector<bool> isCommon(n, true);
		vector<int> totals(n, 0);
		for (const auto& edge : binEdges) {
			// Update total.
			totals[edge.first]++;
			totals[edge.second]++;
		}

		bool hasRemoved = true;
		while (binEdges.size() > 1 && hasRemoved) {
			// Update commons.
			for (int i = 0; i < totals.size(); i++)
				isCommon[i] = totals[i] > 1;

			// Remove leafs.
			hasRemoved = false;
			for (auto it = binEdges.begin(); it != binEdges.end();) {
				// Check if leaf.
				if ((totals[it->first] == 1 && !isCommon[it->first]) ||
					(totals[it->second] == 1 && !isCommon[it->second])) {
					// Decrement.
					totals[it->first]--;
					totals[it->second]--;
					// Remove.
					it = binEdges.erase(it);
					// Update details.
					hasRemoved = true;
				} else {
					it++;
				}
			}
		}

		vector<int> remainingNodes;
		for (int i = 0; i < totals.size(); i++)
			if (isCommon[i])
				remainingNodes.emplace_back(i);
		return remainingNodes;
	}
};
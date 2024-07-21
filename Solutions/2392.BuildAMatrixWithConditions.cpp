class Solution {
public:
	const bool resolveGraph(const vector<vector<int>>& conditions, const int k, vector<int>& order) {
		// Get graph.
		vector<vector<int>> graph(k + 1);
		for (const vector<int>& condition : conditions)
			graph[condition[0]].emplace_back(condition[1]);

		// Setup calculation variables.
		const int n = graph.size();

		// Get offsets from above count.
		vector<int> offsets(k + 1, 0);
		for (int i = 0; i < n; i++)
			for (const int below : graph[i])
				offsets[below]++;

		// Find those at top of graph.
		queue<int> activeNodes;
		for (int i = 1; i <= k; i++)
			if (offsets[i] == 0)
				activeNodes.push(i);

		// Resolve order.
		while (!activeNodes.empty()) {
			// Get node.
			const int node = activeNodes.front();
			activeNodes.pop();

			// Add to order.
			order.push_back(node);

			// Process adjacent.
			for (const int below : graph[node])
				if (--offsets[below] == 0)
					activeNodes.push(below);
		}

		// Success.
		return order.size() == k;
	}

	vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Sort into orders.
		vector<int> rowOrder, colOrder;
		if (!resolveGraph(rowConditions, k, rowOrder) ||
			!resolveGraph(colConditions, k, colOrder)) return {};

		// Remap indices.
		unordered_map<int, int> rowMap(k), colMap(k);
		for (int i = 0; i < k; i++) {
			rowMap[rowOrder[i]] = i;
			colMap[colOrder[i]] = i;
		}

		// Set matrix.
		vector<vector<int>> result(k, vector<int>(k, 0));
		for (int i = 1; i <= k; i++)
			result[rowMap[i]][colMap[i]] = i;

		return result;
	}
};
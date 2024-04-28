class Solution {
public:
	struct SumCount {
		int sum, count;
	};

	// Groupies.
	vector<vector<int>> tree;
	map<pair<int, int>, SumCount> cache;
	vector<int> count, sum;

	void calculateCount(const int target, const int caller) {
		for (int i = 0; i < tree[target].size(); i++) {
			const int node = tree[target][i];
			if (node == caller) continue;

			// Recurse count.
			calculateCount(node, target);
			count[target] += count[node];
			sum[target] += sum[node] + count[node];
		}
	}

	void calculateSum(const int target, const int caller) {
		for (int i = 0; i < tree[target].size(); i++) {
			const int node = tree[target][i];
			if (node == caller) continue;

			// Recurse sum.
			sum[node] = sum[target] - count[node] + (count.size() - count[node]);
			calculateSum(node, target);
		}
	}

	vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
		// Initialize groupies.
		tree = vector<vector<int>>(n);
		cache.clear();
		count = vector<int>(n, 1);
		sum = vector<int>(n, 0);

		// Create graph.
		for (int i = 0; i < edges.size(); i++) {
			// Add graph connections.
			tree[edges[i][0]].emplace_back(edges[i][1]);
			tree[edges[i][1]].emplace_back(edges[i][0]);
		}

		// Calculate count.
		calculateCount(0, -1);
		// Calculate sum.
		calculateSum(0, -1);

		return sum;
	}
};
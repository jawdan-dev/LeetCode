class Solution {
public:
	int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Map out graph.
		unordered_map<int, list<int>> graph;
		for (const vector<int>& edge : edges) {
			const int u = edge[0], v = edge[1];
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		// Calculation variables.
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
		vector<int> uniqueVisits(n + 1, 0);
		vector<int> minimumNodeTime(n + 1, -1);

		//  Dijkstra's algorithm time.
		// (Time, Node).
		queue.push({ 0, 1 });
		while (!queue.empty()) {
			// Get highest priority node.
			auto [nodeTime, nodeIndex] = queue.top();
			queue.pop();

			// Skip if already visited or past second minimum.
			if (minimumNodeTime[nodeIndex] == nodeTime || uniqueVisits[nodeIndex] >= 2)
				continue;

			// Update tracking variables.
			uniqueVisits[nodeIndex]++;
			minimumNodeTime[nodeIndex] = nodeTime;

			// Second minimum found.
			if (nodeIndex == n && uniqueVisits[nodeIndex] == 2)
				return minimumNodeTime[nodeIndex];

			// Calculate the leaving time (waiting for the green light)
			if ((nodeTime / change) % 2 != 0)
				nodeTime = (nodeTime / change + 1) * change;

			// Calculate neighbours next.
			for (int neighbour : graph[nodeIndex])
				queue.push({ nodeTime + time, neighbour });
		}

		// No second minimum found.
		return -1;
	}
};
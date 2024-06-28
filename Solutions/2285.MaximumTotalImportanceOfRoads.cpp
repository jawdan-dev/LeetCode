class Solution {
public:
	long long maximumImportance(int n, vector<vector<int>>& roads) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Get city connection count.
		vector<long long> cityConnections(n, 0);
		const int r = roads.size();
		for (int i = 0; i < r; i++) {
			cityConnections[roads[i][0]]++;
			cityConnections[roads[i][1]]++;
		}

		// Sort by connection count.
		sort(cityConnections.begin(), cityConnections.end());

		// Calculate total roads.
		long long total = 0;
		for (long long i = 0; i < n; i++) {
			// Assign place in sorted list as score, multiply by it, and add.
			total += (i + 1) * cityConnections[i];
		}
		return total;
	}
};
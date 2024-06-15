class Solution {
public:
	int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Create sorted list (by capital) of projects.
		const int n = min(profits.size(), capital.size());
		vector<pair<int, int>> projects;
		projects.reserve(n);
		for (int i = 0; i < n; i++) projects.emplace_back(capital[i], profits[i]);
		sort(projects.begin(), projects.end());

		// Work projects.
		int workingIndex = 0;
		priority_queue<int> availableProfit;
		while (k > 0) {
			// Decrement k.
			k--;

			// Add available projects to list.
			while (workingIndex < n && projects[workingIndex].first <= w)
				availableProfit.push(projects[workingIndex++].second);

			// Make sure we've got something to do.
			if (availableProfit.empty()) break;

			// Take project with maximum profits.
			w += availableProfit.top();
			availableProfit.pop();
		}
		return w;
	}
};
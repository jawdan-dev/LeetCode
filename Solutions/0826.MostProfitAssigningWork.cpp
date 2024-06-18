class Solution {
public:
	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int jobN = min(difficulty.size(), profit.size());
		const int workerN = worker.size();

		// Create job pair list.
		vector<pair<int, int>> jobs;
		for (int i = 0; i < jobN; i++)
			jobs.emplace_back(difficulty[i], profit[i]);

		// Sort jobs and workers.
		sort(jobs.begin(), jobs.end());
		sort(worker.begin(), worker.end());

		// Process by best jobs.
		int jobIndex = 0;
		int totalProfit = 0;
		priority_queue<int> availableProfit;
		for (int i = 0; i < workerN; i++) {
			// Add possible jobs to priority queue.
			while (jobIndex < jobN && jobs[jobIndex].first <= worker[i]) {
				availableProfit.push(jobs[jobIndex].second);
				jobIndex++;
			}

			// Go to next if no jobs are available.
			if (availableProfit.empty()) continue;

			// Add to profit.
			totalProfit += availableProfit.top();
		}
		return totalProfit;
	}
};
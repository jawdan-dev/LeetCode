class Solution {
public:
	double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Get proportional wage quality.
		vector<pair<double, int>> wageQuality;
		const int n = min(quality.size(), wage.size());
		for (int i = 0; i < n; i++)
			wageQuality.emplace_back(pair<double, int>((double)wage[i] / (double)quality[i], i));
		sort(wageQuality.begin(), wageQuality.end());


		// Accept the first k workers.
		priority_queue<int> workerHeap;
		int qualityTotal = 0;
		double wageMax = 0;
		for (int i = 0; i < k; i++) {
			qualityTotal += quality[wageQuality[i].second];
			wageMax = max(wageMax, wageQuality[i].first);
			//
			workerHeap.push(quality[wageQuality[i].second]);
		}

		// Compare against other workers.
		double result = (double)qualityTotal * wageMax;
		for (int i = k; i < n; i++) {
			wageMax = max(wageMax, wageQuality[i].first);
			qualityTotal -= workerHeap.top();
			workerHeap.pop();

			qualityTotal += quality[wageQuality[i].second];
			workerHeap.push(quality[wageQuality[i].second]);

			result = min(result, (double)qualityTotal * wageMax);
		}

		return result;
	}
};
class Solution {
public:
	double averageWaitingTime(vector<vector<int>>& customers) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = customers.size();
		const double avgMultiplier = 1.0 / (double)n;

		// Calculate average wait time.
		double avgWait = (double)customers[0][1] * avgMultiplier;
		int lastEnd = customers[0][0] + customers[0][1]; // First customer doesnt wait.
		for (int i = 1; i < n; i++) {
			const int
				arrivalTime = customers[i][0],
				prepTime = customers[i][1];

			// The customer's minimum wait time.
			int wait = prepTime;

			// Check if customer had to wait for the prep to start.
			if (lastEnd > arrivalTime)
				wait += lastEnd - arrivalTime;

			// Add to average.
			avgWait += (double)wait * avgMultiplier;

			// Update last end time.
			if (arrivalTime > lastEnd) lastEnd = arrivalTime + prepTime;
			else lastEnd += prepTime;
		}
		return avgWait;
	}
};
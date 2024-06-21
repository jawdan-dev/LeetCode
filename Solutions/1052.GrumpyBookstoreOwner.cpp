class Solution {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = min(customers.size(), grumpy.size());

		// Get initial total.
		int totalSatisfied = 0;
		for (int i = 0; i < n; i++)
			if (!grumpy[i] || i < minutes)
				totalSatisfied += customers[i];

		// Calculate max satisfied via window.
		int maxSatisfied = totalSatisfied;
		for (int i = minutes; i < n; i++) {
			// Remove left-most minute.
			const int left = i - minutes;
			if (grumpy[left])
				totalSatisfied -= customers[left];

			// Add right-most minute.
			if (grumpy[i])
				totalSatisfied += customers[i];

			// Update max.
			maxSatisfied = max(maxSatisfied, totalSatisfied);
		}

		// Return max satisfied.
		return maxSatisfied;
	}
};
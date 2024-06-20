class Solution {
public:
	int maxDistance(vector<int>& position, int m) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Setup environment.
		const int n = position.size();
		sort(position.begin(), position.end());

		// Binary search to goal.
		int maxMinDistance = 0;
		int left = 0, right = position.back();
		while (left <= right) {
			const int mid = (left + right) / 2;

			// Get valid position count.
			int totalValidPositions = 1, lastPosition = position[0];
			for (int i = 1; i < n && totalValidPositions < m; i++) {
				if (position[i] - lastPosition >= mid) {
					totalValidPositions++;
					lastPosition = position[i];
				}
			}

			// Handle search.
			if (totalValidPositions >= m) {
				left = mid + 1;
				// Update max min distance.
				maxMinDistance = max(maxMinDistance, mid);
			} else {
				right = mid - 1;
			}
		}
		return maxMinDistance;
	}
};
class Solution {
public:
	int numTeams(vector<int>& rating) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = rating.size();

		// Calculate teams.
		int totalTeams = 0;
		for (int i = 0; i < n; i++) {
			int leftSmaller = 0, leftLarger = 0, rightSmaller = 0, rightLarger = 0;

			// Search left.
			for (int left = i - 1; left >= 0; left--)
				if (rating[left] < rating[i])
					leftSmaller++;
				else
					leftLarger++;

			// Search right.
			for (int right = i + 1; right < n; right++)
				if (rating[right] < rating[i])
					rightSmaller++;
				else
					rightLarger++;

			// Add found teams to total teams.
			const int foundTeams = (leftSmaller * rightLarger) + (leftLarger * rightSmaller);
			totalTeams += foundTeams;
		}

		return totalTeams;

	}
};
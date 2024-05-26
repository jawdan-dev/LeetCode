class Solution {
public:
	static constexpr int modFactor = 1000000007;
	static constexpr int maxAbsences = 2;
	static constexpr int maxLates = 3;

	int checkRecord(int n) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Setup layers.
		int
			** previousLayer = new int* [maxAbsences],
			** activeLayer = new int* [maxAbsences];
		for (int i = 0; i < maxAbsences; i++) {
			previousLayer[i] = new int[maxLates];
			activeLayer[i] = new int[maxLates];
		}

		// Initialize starting layer.
		for (int j = 0; j < maxAbsences; j++)
			for (int k = 0; k < maxLates; k++)
				previousLayer[j][k] = 1;

		for (int i = 0; i <= n; i++) {
			// Clear layer.
			for (int j = 0; j < maxAbsences; j++)
				for (int k = 0; k < maxLates; k++)
					activeLayer[j][k] = 0;

			// Process layer.
			for (int j = 0; j < maxAbsences; j++) {
				for (int k = 0; k < maxLates; k++) {
					// Present.
					activeLayer[j][k] += previousLayer[j][2];

					// Late.
					if (k > 0) {
						activeLayer[j][k] += previousLayer[j][k - 1];
						activeLayer[j][k] %= modFactor;
					}

					// Absent.
					if (j > 0) {
						activeLayer[j][k] += previousLayer[j - 1][2];
						activeLayer[j][k] %= modFactor;
					}
				}
			}

			// Swap layers.
			int** temp = activeLayer;
			activeLayer = previousLayer;
			previousLayer = temp;
		}

		// Return records with 1 absence and 2 lates or better.
		return activeLayer[1][2];
	}
};
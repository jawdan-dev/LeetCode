class Solution {
public:
	int maximumGain(string s, int x, int y) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = s.size(), lesser = min(x, y);

		// Handle search and score compression.
		int totalScore = 0;
		int ACount = 0, BCount = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'a') {
				// Update score (prioritizing higher).
				if (x < y && BCount > 0) {
					BCount--;
					totalScore += y;
				} else {
					ACount++;
				}
			} else if (s[i] == 'b') {
				// Update score (prioritizing higher).
				if (x > y && ACount > 0) {
					ACount--;
					totalScore += x;
				} else {
					BCount++;
				}
			} else {
				// Other character.
				totalScore += min(ACount, BCount) * lesser;
				// Reset count.
				ACount = 0;
				BCount = 0;
			}
		}
		// Find score update.
		totalScore += min(ACount, BCount) * lesser;
		return totalScore;
	}
};
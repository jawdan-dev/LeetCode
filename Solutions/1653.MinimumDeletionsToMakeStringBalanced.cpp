class Solution {
public:
	int minimumDeletions(string s) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = s.size();

		// Calculate.
		int totalRemovals = 0, canBeRemoved = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'b') {
				// Add potentially removable character.
				canBeRemoved++;
			} else if (canBeRemoved > 0) {
				// Remove character.
				totalRemovals++;
				canBeRemoved--;
			}
		}
		return totalRemovals;
	}
};
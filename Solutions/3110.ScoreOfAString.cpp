class Solution {
public:
	int scoreOfString(string s) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Total adjacent scores.
		int score = 0;
		for (int i = s.size() - 1; i > 0; i--) {
			// Get working characters.
			const char a = s[i - 1], b = s[i];
			// Cheeky abs.
			score += (a > b) ? (a - b) : (b - a);
		}
		return score;
	}
};
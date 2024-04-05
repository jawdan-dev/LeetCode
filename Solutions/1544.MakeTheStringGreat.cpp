class Solution {
public:
	inline const char toLower(const char c) {
		return c >= 'a' ? (c - ('a' - 'A')) : c;
	}

	string makeGood(string s) {
		for (int i = 1; i < s.length(); ) {
			const char c1 = toLower(s[i - 1]);
			const char c2 = toLower(s[i]);

			// Compare substring.
			if (c1 != c2 || s[i - 1] == s[i]) {
				// Substring good. Skip.
				i++;
				continue;
			}

			// Remove substring.
			s.erase(i - 1, 2);
			if (i > 1) i--;
		}

		// Return good string.
		return s;
	}
};
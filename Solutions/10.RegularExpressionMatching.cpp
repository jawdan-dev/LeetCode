class Solution {
public:
	const bool characterMatches(const char c, const char p) {
		// Check character match.
		return p == '.' || c == p;
	}

	const bool tryMatch(const char* s, const int sLen, const char* p, const int pLen) {
		// Perfectly matched.
		if (sLen <= 0 && pLen <= 0) return true;
		// End of pattern.
		if (pLen <= 0) return false;

		// Check for '*' pattern.
		if (pLen >= 2 && p[1] == '*') {
			int offset = 0;
			for (int i = 0; i <= sLen; i++) {
				// Skip first.
				if (i > 0 && !characterMatches(s[i - 1], p[0])) break;

				// Check for pattern match.
				if (tryMatch(s + i, sLen - i, p + 2, pLen - 2)) return true;
			}

			// Not possible match with *.
			return false;
		} else if (sLen <= 0) {
			// No string left matches the pattern.
			return false;
		}

		// Check character and match recursively.
		return characterMatches(s[0], p[0]) && tryMatch(s + 1, sLen - 1, p + 1, pLen - 1);
	}

	bool isMatch(string s, string p) {
		return tryMatch(s.c_str(), s.size(), p.c_str(), p.size());
	}
};
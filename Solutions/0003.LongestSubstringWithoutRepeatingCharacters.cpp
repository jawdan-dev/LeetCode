class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// Easier string manipulations.
		const char* str = s.c_str();
		const int strLen = s.length();

		// Lookup storage.
		bool lookup[256];
		memset(lookup, 0, sizeof(lookup));

		// Find substrings.
		int currentLength = 0, longestLength = 0;
		for (int i = 0; i < strLen; i++) {
			for (int j = i + currentLength; j < strLen; j++) {
				// Duplicate found.
				if (lookup[str[j]]) break;

				// Add to right.
				lookup[str[j]] = true;
				currentLength++;
			}

			// Use size.
			if (longestLength < currentLength)
				longestLength = currentLength;

			// Remove from left.
			lookup[str[i]] = false;
			currentLength--;
		}

		// Output longest length.
		return longestLength;
	}
};
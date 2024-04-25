class Solution {
public:
	int longestIdealString(string s, int k) {
		// Length storage.
		int maxLengthArr[26];
		memset(maxLengthArr, 0, sizeof(maxLengthArr));

		// Get to work.
		for (int i = 0; i < s.size(); i++) {
			// Get iteration values.
			const unsigned char
				left = max(s[i] - k, (int)'a') - 'a',
				right = min(s[i] + k, (int)'z') - 'a';
			const int
				fillVal = maxLengthArr[s[i] - 'a'] + 1;

			// Fill in max.
			for (unsigned char j = left; j <= right; j++)
				maxLengthArr[j] = max(maxLengthArr[j], fillVal);
		}

		// Get longest.
		int longest = 0;
		for (int i = 0; i < sizeof(maxLengthArr) / sizeof(*maxLengthArr); i++)
			longest = max(longest, maxLengthArr[i]);

		return longest;
	}
};
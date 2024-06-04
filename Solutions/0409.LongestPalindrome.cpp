class Solution {
public:
	unsigned int characterCounts[26 * 2];


	int longestPalindrome(string s) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Clear memory.
		memset(characterCounts, 0, sizeof(characterCounts));

		// Create character count infromation.
		const int n = s.size();
		for (int i = 0; i < n; i++) {
			const char c = s[i];
			if ('a' <= c && c <= 'z') characterCounts[c - 'a']++;
			else if ('A' <= c && c <= 'Z') characterCounts[(c - 'A') + 26]++;
		}

		// Count max palindrome length.
		int maxPalinDrome = 0;
		// Add all double characters onto count.
		for (int i = 0; i < sizeof(characterCounts) / sizeof(*characterCounts); i++) {
			const int mod = characterCounts[i] % 2;
			maxPalinDrome += characterCounts[i] - mod;
			characterCounts[i] = mod;
		}
		// Check for palindrome center (odd character count).
		for (int i = 0; i < sizeof(characterCounts) / sizeof(*characterCounts); i++) {
			if (characterCounts[i] != 1) continue;
			maxPalinDrome++;
			break;
		}

		return maxPalinDrome;
	}
};
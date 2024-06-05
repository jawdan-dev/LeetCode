class Solution {
public:
	vector<string> commonChars(vector<string>& words) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Create calculation variables.
		unsigned int minCharCounts[26], workingCharCounts[26];
		for (int i = 0; i < sizeof(minCharCounts) / sizeof(*minCharCounts); i++)
			minCharCounts[i] = UINT_MAX;

		// Count characters.
		for (int i = 0; i < words.size(); i++) {
			// Count characters in word.
			memset(workingCharCounts, 0, sizeof(workingCharCounts));
			for (int j = 0; j < words[i].size(); j++)
				workingCharCounts[words[i][j] - 'a']++;

			// Check for duplicates accross words so far.
			for (int j = 0; j < sizeof(minCharCounts) / sizeof(*minCharCounts); j++)
				minCharCounts[j] = min(minCharCounts[j], workingCharCounts[j]);
		}

		// Add characters (strings for some stupid reason?????) to result.
		vector<string> repeatedChars;
		string s = "_";
		for (int i = 0; i < sizeof(minCharCounts) / sizeof(*minCharCounts); i++) {
			if (minCharCounts[i] < UINT_MAX && minCharCounts[i] >= 1) {
				// Convert to string.
				s[0] = i + 'a';

				// Add to result.
				for (int j = 0; j < minCharCounts[i]; j++)
					repeatedChars.push_back(s);
			}
		}
		return repeatedChars;
	}
};
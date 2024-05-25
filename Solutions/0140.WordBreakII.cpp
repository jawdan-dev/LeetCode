class Solution {
public:
	unordered_set<string> m_dict;
	string* m_string;
	int m_n;

	vector<string> m_workingWords, m_brokenStrings;

	void breakWords(const int index, const int count) {
		if (index + count > m_n) {
			// Index can only be more than n for end of string.
			if (index < m_n) return;

			// Add string to list.
			const int brokenIndex = m_brokenStrings.size();
			m_brokenStrings.emplace_back("");

			// Convert working set into string directly.
			const int wordsEnd = m_workingWords.size();
			const int spaceEnd = wordsEnd - 1;
			for (int i = 0; i < wordsEnd; i++) {
				// Add word + space.
				m_brokenStrings[brokenIndex] += m_workingWords[i] + " ";
			}
			// Remove trailing space.
			m_brokenStrings[brokenIndex].pop_back();

			return;
		}

		// Check for longer variations on the same word.
		breakWords(index, count + 1);

		// Check if word exists in dictionary.
		const string word = m_string->substr(index, count);
		if (m_dict.find(word) == m_dict.end()) return;

		// Add word to working set.
		m_workingWords.push_back(word);
		// Check for words after.
		breakWords(index + count, 1);
		// Remove word from working set.
		m_workingWords.pop_back();
	}

	vector<string> wordBreak(string s, vector<string>& wordDict) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Setup calculation variables.
		m_dict = unordered_set<string>(wordDict.begin(), wordDict.end());
		m_string = &s;
		m_n = m_string->size();

		// Break words.
		breakWords(0, 1);
		return m_brokenStrings;
	}
};
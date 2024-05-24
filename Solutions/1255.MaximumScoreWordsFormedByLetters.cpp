class Solution {
public:
	int m_total;

	vector<string>* m_words;
	int m_n;
	int* m_scores;

	int m_workingScore;
	uint8_t m_workingUses[26];

	void getMaxScoreWordsTotal(const int index) {
		// Exit case.
		if (index >= m_n) {
			// Max out total.
			m_total = max(m_total, m_workingScore);
			return;
		}

		// Work on non-derived subsets.
		getMaxScoreWordsTotal(index + 1);


		// Get word.
		const string& word = (*m_words)[index];
		// Check if word is valid.
		int validEnd;
		for (validEnd = 0; validEnd < word.size(); validEnd++) {
			const uint8_t key = word[validEnd] - 'a';
			// Update characters used.
			if (m_workingUses[key] > 0) m_workingUses[key]--;
			else break;
		}

		// Work on valid word.
		if (validEnd >= word.size()) {
			// Get score.
			int score = 0;
			for (int i = 0; i < word.size(); i++)
				score += m_scores[word[i] - 'a'];

			// Uses score.
			m_workingScore += score;

			// Work on derived subsets.
			getMaxScoreWordsTotal(index + 1);

			// Stop using score.
			m_workingScore -= score;
		}

		// Reset uses.
		for (int i = 0; i < validEnd; i++)
			m_workingUses[word[i] - 'a']++;
	}

	int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Set calculation variables.
		m_total = 0;
		m_words = &words;
		m_n = m_words->size();
		m_scores = score.data();
		m_workingScore = 0;

		// Setup alphabet max uses.
		memset(m_workingUses, 0, sizeof(m_workingUses));
		for (int i = 0; i < letters.size(); i++)
			m_workingUses[letters[i] - 'a']++;

		// TODO: Remove words that are always invalid.

		// Calculate total.
		getMaxScoreWordsTotal(0);
		return m_total;
	}
};
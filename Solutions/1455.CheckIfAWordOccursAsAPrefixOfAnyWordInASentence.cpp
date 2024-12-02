class Solution {
public:
	int isPrefixOfWord(string sentence, string searchWord) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);


		const int wordLength = searchWord.size();
		const int searchLength = sentence.size() - wordLength;

		int wordCount = 0;
		for (int i = 0; i <= searchLength; i++) {
			bool wordFound = true;
			for (int j = 0; j < wordLength && wordFound; j++)
				if (sentence[i + j] != searchWord[j])
					wordFound = false;

			if (wordFound)
				return wordCount + 1;

			while (i <= searchLength && sentence[i] != ' ') i++;
			wordCount++;
		}

		return -1;
	}
};
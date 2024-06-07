class Solution {
public:
	struct StringNode {
		string m_string;
		StringNode* m_children[26];

		StringNode() : m_string("") {
			// Set children to nullptr.
			for (int i = 0; i < sizeof(m_children) / sizeof(*m_children); i++)
				m_children[i] = nullptr;
		}

		void addString(const char* string, const char* baseString) {
			// Check if string finished.
			if (string[0] == '\0') {
				// Valid end point.
				m_string = baseString;
				return;
			}

			// Get child.
			StringNode*& child = m_children[string[0] - 'a'];
			if (child == nullptr)
				// Create child.
				child = new StringNode();

			// Add remainder of string.
			child->addString(string + 1, baseString);
		}

		const char* validString(const char* string) {
			if (string[0] == '\0' || m_string[0] != '\0') return m_string.c_str();

			// Get child.
			StringNode*& child = m_children[string[0] - 'a'];

			// Child if child exists.
			if (child == nullptr) return m_string.c_str();

			// Recurse.
			return child->validString(string + 1);
		}
	};

	string replaceWords(vector<string>& dictionary, string sentence) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Create root.
		StringNode root;
		for (const string& word : dictionary)
			root.addString(word.c_str(), word.c_str());

		// Create resultant sentence.
		const int n = sentence.size();
		string activeWord, resultantSentence = "";
		for (int i = 0; i < n; i++) {
			// Reset states.
			activeWord = "";

			// Find word in dictionary.
			for (; i < n && sentence[i] != ' '; i++) {
				// Update active word.
				activeWord += sentence[i];
			}

			// Add space.
			if (resultantSentence.size() > 0) resultantSentence += ' ';

			// Get valid word.
			const char* validWord = root.validString(activeWord.c_str());
			resultantSentence += (validWord[0] != '\0') ? validWord : activeWord;
		}

		return resultantSentence;
	}
};
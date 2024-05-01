class Solution {
public:
	string reversePrefix(string word, char ch) {
		// Find reverse start.
		int index = 0;
		while (index < word.size() && word[index] != ch) index++;
		if (index >= word.size()) return word;

		// Reverse prefix.
		reverse(word.begin(), word.begin() + index + 1);
		return word;
	}
};
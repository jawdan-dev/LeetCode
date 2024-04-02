class Solution {
public:
    int lengthOfLastWord(string s) {
        // Remove spaces.
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') i--;

        // Count word.
        int wordLength = i;
        while (i >= 0 && s[i] != ' ') i--;
        wordLength = wordLength - i;

        // Return length;
        return wordLength;
    }
};
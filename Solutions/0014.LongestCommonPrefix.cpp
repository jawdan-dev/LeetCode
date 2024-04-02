class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Get min string length.
        int maxLength = strs[0].length();
        for (int i = 1; i < strs.size(); i++) maxLength = min(maxLength, (int)strs[i].length());

        // Find longest common prefix.
        int prefixLength = 0;
        bool prefixClash = false;
        for (; prefixLength < maxLength; prefixLength++) {
            // Get common prefix.
            char targetPrefix = strs[0][prefixLength];

            // Check prefixes.
            for (int j = 1; j < strs.size(); j++) {
                // Check matching.
                if (strs[j][prefixLength] == targetPrefix) continue;

                // Prefix clashes.
                prefixClash = true;
                break;
            }

            if (prefixClash) break;
        }

        // Retrun substring.
        return strs[0].substr(0, prefixLength);
    }
};
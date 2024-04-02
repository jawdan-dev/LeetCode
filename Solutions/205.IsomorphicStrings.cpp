class Solution {
public:
	bool isIsomorphic(string s, string t) {
		// Length check.
		if (s.size() != t.size()) return false;

		// Lookup tables.
		map<char, char> isoLookup;
		set<char> usedCharacters;

		// Process.
		for (int i = 0; i < s.size(); i++) {
			// The characters to compare.
			const char a = s[i];
			const char b = t[i];

			// Find lookup entry.
			auto it = isoLookup.find(a);
			if (it == isoLookup.end()) {
				// Check that character b is not already in use.
				if (usedCharacters.find(b) != usedCharacters.end()) return false;

				// Create lookup entry.
				isoLookup.emplace(a, b);
				usedCharacters.emplace(b);
				continue;
			}

			// Check entry matches.
			if (it->second != b) return false;
		}

		// No errors occurred, must be isomorphic.
		return true;
	}
};
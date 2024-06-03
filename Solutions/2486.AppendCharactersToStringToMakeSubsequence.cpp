class Solution {
public:
	int appendCharacters(string s, string t) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = s.size(), tn = t.size();

		// Find matching count.
		int matchingFound = 0;
		for (int j = 0; j < n; j++)
			if (s[j] == t[matchingFound])
				matchingFound++;

		// Return the remaining to match t's length with max found.
		return tn - matchingFound;
	}
};
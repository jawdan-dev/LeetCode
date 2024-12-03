class Solution {
public:
	string addSpaces(string s, vector<int>& spaces) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		//sort(spaces.rbegin(), spaces.rend());

		string result;
		result.reserve(s.size() + spaces.size());

		int stringI = 0, spaceI = 0;
		while (stringI < s.size() && spaceI < spaces.size()) {
			while (stringI < spaces[spaceI])
				result += s[stringI++];

			result += ' ';
			spaceI++;
		}
		while (stringI < s.size())
			result += s[stringI++];

		return result;
	}
};
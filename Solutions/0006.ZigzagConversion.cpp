// PAYPALISHIRING
// 1     2     3
//  1   2 3   4 5
//   1 2   3 4
//    1     2
// PINALSIGYAHRPI

class Solution {
public:
	string convert(string s, int numRows) {
		// Ignore sigle row case.
		if (numRows <= 1) return s;

		// Result storage.
		string result;
		result.reserve(s.size());

		// Calculatation storage.
		vector<vector<int>> locations(numRows);

		// Calculate offsets.
		bool flag;
		int layer = 0;
		for (int i = 0; i < s.size(); i++) {
			// Descending.
			locations[layer].emplace_back(i);

			// Update flag.
			if (layer == 0) flag = true;
			else if (layer == numRows - 1) flag = false;
			layer += flag ? 1 : -1;
		}

		// Create output string.
		for (int i = 0; i < locations.size(); i++)
			for (int j = 0; j < locations[i].size(); j++)
				result += s[locations[i][j]];

		// Return string.
		return result;
	}
};
class Solution {
public:
	string reverseParentheses(string s) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = s.size();
		stack<int> openBraces;

		// Reversy.
		string res = "";
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') {
				// Mark beginning of partition.
				openBraces.push(res.size());
			} else if (s[i] == ')') {
				// Reverse partition.
				reverse(res.begin() + openBraces.top(), res.begin() + res.size());
				openBraces.pop();
			} else {
				// Add partition data.
				res += s[i];
			}
		}

		return res;
	}
};
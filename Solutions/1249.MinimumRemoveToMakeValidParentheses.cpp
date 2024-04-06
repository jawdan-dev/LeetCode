class Solution {
public:
	string minRemoveToMakeValid(string s) {
		// Find left over open parentheses + invalid close parentheses.
		stack<int> openParentheses, invalidParentheses;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				openParentheses.push(i);
			} else if (s[i] == ')') {
				if (!openParentheses.empty()) openParentheses.pop();
				else invalidParentheses.push(i);
			}
		}

		// Remove invalid parentheses.
		while (!openParentheses.empty()) {
			s.erase(openParentheses.top(), 1);
			openParentheses.pop();
		}
		while (!invalidParentheses.empty()) {
			s.erase(invalidParentheses.top(), 1);
			invalidParentheses.pop();
		}

		// Return fixed string.
		return s;
	}
};
class Solution {
public:
	string removeKdigits(string num, int k) {
		if (k >= num.size()) return "0";

		// Process stack.
		stack<char> numStack;
		for (int i = 0; i < num.size(); i++) {
			char n = num[i];
			while (k > 0 && !numStack.empty() && n < numStack.top()) {
				numStack.pop();
				k--;
			}
			numStack.push(n);
		}

		// Trim remaining.
		while (k > 0 && !numStack.empty()) {
			numStack.pop();
			k--;
		}

		// Get output string.
		string output;
		output.reserve(numStack.size());
		while (!numStack.empty()) {
			output += numStack.top();
			numStack.pop();
		}
		reverse(output.begin(), output.end());

		// Trim zeros.
		int trimOffset = 0;
		while (output[trimOffset] == '0') trimOffset++;
		if (trimOffset) output = trimOffset < output.size() ? output.substr(trimOffset) : "0";

		// Return output.
		return output;
	}
};
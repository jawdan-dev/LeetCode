class Solution {
public:
	bool isValid(string s) {
		stack<char> activeScope;

		// Process String.
		for (int i = 0; i < s.size(); i++) {
			switch (s[i]) {
				// Invalid character.
				default: return false;

				// Handle open-scopes.
				case '(':
				case '{':
				case '[': {
					activeScope.emplace(s[i]);
				} break;

				// Handle close-scopes.
				case ')':
				case '}':
				case ']': {
					// Get equivalent open character.
					char openCharacter;
					switch (s[i]) {
						case ')': openCharacter = '('; break;
						case '}': openCharacter = '{'; break;
						case ']': openCharacter = '['; break;
					}

					// Check stack for matching open.
					if (activeScope.size() <= 0 || activeScope.top() != openCharacter) return false;

					// Remove from stack.
					activeScope.pop();
				} break;
			}
		}

		// Stack empty == valid.
		return activeScope.size() == 0;
	}
};
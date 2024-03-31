class Solution {
public:
	int reverse(int x) {
		unsigned long long reversed = 0;

		// Get absolute value of x (as mod is scuffed below 0).
		unsigned long long abs = x >= 0 ? x : -(long long)x;
		while (abs > 0) {
			// Shift + Add to reversed value.
			reversed *= 10ull;
			reversed += abs % 10ull;
			// Update absolute x.
			abs /= 10ull;
		}

		// Compare against max.
		if (reversed > INT_MAX) return 0;

		// Return signed answer.
		return x >= 0 ? reversed : -reversed;
	}
};
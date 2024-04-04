class Solution {
public:
	int maxDepth(string s) {
		if (s == "") return 0;

		// Calculate max depth.
		int activeDepth = 0,
			maxDepth = activeDepth;
		for (const char* c = s.c_str(); *c; c++) {
			if (*c == '(') {
				// Update depth.
				activeDepth++;

				// Update max.
				if (maxDepth < activeDepth)
					maxDepth = activeDepth;
			} else if (*c == ')') {
				// Update depth.
				activeDepth--;
			}
		}

		// Return max depth.
		return maxDepth;
	}
};
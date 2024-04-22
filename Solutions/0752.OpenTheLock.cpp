class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		// TODO: A more a* approach would be cooler.

		set<string>
			deadendSet(deadends.begin(), deadends.end()),
			activeSet, usedSet;
		activeSet.emplace("0000");
		usedSet.emplace("0000");

		// Early exits.
		if (deadendSet.find("0000") != deadendSet.end()) return -1;
		if (target == "0000") return 0;

		// Find total steps.
		int steps = 0;
		string newString;
		const int checks[] = { 9, 1 };
		set<string> newActiveSet;
		while (!activeSet.empty()) {
			// Update steps.
			steps++;

			// Find target / Create new active set.
			newActiveSet.clear();
			for (const string& str : activeSet) {
				// Move a wheel.
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < sizeof(checks) / sizeof(*checks); j++) {
						// Create new combo.
						newString = str;
						newString[i] = (((newString[i] + checks[j]) - '0') % 10) + '0';

						// Check against target.
						if (newString == target) return steps;

						// Check if already used.
						if (usedSet.find(newString) != usedSet.end()) continue;
						usedSet.emplace(newString);

						// Check if deadend.
						if (deadendSet.find(newString) != deadendSet.end()) continue;

						// Add to active set.
						newActiveSet.emplace(newString);
					}
				}
			}

			// Update active set.
			activeSet = newActiveSet;
		}

		// Unable to find.
		return -1;
	}
};
class Solution {
public:
	int letterFrequency[26];
	int minimumPushes(string word) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = word.size();

		// Create frequency map.
		memset(letterFrequency, 0, sizeof(letterFrequency));
		for (int i = 0; i < n; i++)
			letterFrequency[word[i] - 'a']++;

		// NOTE: A negative press count is used for this, as it sorts the set in reverse.
		// Convert to set.
		set<pair<int, char>> characterMap;
		for (int i = 0; i < sizeof(letterFrequency) / sizeof(*letterFrequency); i++)
			if (letterFrequency[i] > 0)
				characterMap.emplace(-letterFrequency[i], i + 'a');

		// Caculate total key presses.
		int totalKeysPressed = 0;
		int layer = 0, remainingForLayer = 0;
		for (const auto& key : characterMap) {
			// Make sure we are working on a valid layer.
			if (remainingForLayer <= 0) {
				layer++;
				remainingForLayer = 8;
			}

			// Add key to total.
			totalKeysPressed += -key.first * layer;

			// Update counter.
			remainingForLayer--;
		}

		return totalKeysPressed;
	}
};
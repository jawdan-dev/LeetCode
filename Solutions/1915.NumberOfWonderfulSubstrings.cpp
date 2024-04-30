class Solution {
public:
	long long wonderfulSubstrings(string word) {
		constexpr size_t characterExtent = (('j' - 'a') + 1);

		// Count storage.
		constexpr size_t countSize = 1 << characterExtent;
		long long count[countSize];
		memset(count, 0, sizeof(count));
		count[0] = 1;

		// Find total wonderful substrings.
		int mask = 0;
		long long total = 0;
		for (int i = 0; i < word.size(); i++) {
			// Get index + mask.
			const int index = word[i] - 'a';
			mask ^= 1 << index;

			// Add previous to total.
			total += count[mask];

			// Add possible combinations to total.
			for (int i = 0; i < characterExtent; i++)
				total += count[mask ^ (1 << i)];

			// Increment count.
			count[mask]++;
		}
		return total;
	}
};
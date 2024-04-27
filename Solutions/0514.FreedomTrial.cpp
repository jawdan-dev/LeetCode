class Solution {
public:
	const uint32_t closestCW(const string& string, const uint32_t index, const char target) {
		// Find closest clockwise.
		const uint32_t modMax = string.size();
		for (uint32_t i = 0; i < modMax; i++)
			if (string[(index + i) % modMax] == target)
				return i;
		// Not found,, shouldn't happen so we ignore and enjoy a bad result.
		return 0;
	}
	const uint32_t closestCCW(const string& string, const uint32_t index, const char target) {
		// Find closest counter-clockwise.
		const uint32_t modMax = string.size();
		for (uint32_t i = 0; i < string.size(); i++)
			if (string[(index + modMax - i) % modMax] == target)
				return i;
		// Not found,, shouldn't happen so we ignore and enjoy a bad result.
		return 0;
	}

	const uint32_t getSteps(
		map<uint64_t, uint32_t>& cache,
		const string& ring, const uint32_t ringIndex,
		const string& key, const uint32_t keyIndex
	) {
		// End of key check.
		if (keyIndex == key.size()) return 0;

		// Check cache.
		const uint64_t cacheLookupValue = ((uint64_t)ringIndex << 32) | keyIndex;
		auto it = cache.find(cacheLookupValue);
		if (it != cache.end()) return it->second;
		uint32_t score = INT_MAX;

		// Get character distances.
		const uint32_t
			leftDistance = closestCCW(ring, ringIndex, key[keyIndex]),
			rightDistance = closestCW(ring, ringIndex, key[keyIndex]);

		// Get indices.
		const uint32_t
			leftIndex = (ringIndex + ring.size() - leftDistance) % ring.size(),
			rightIndex = (ringIndex + rightDistance) % ring.size();

		// Branch left.
		const uint32_t leftSteps = getSteps(cache, ring, leftIndex, key, keyIndex + 1);
		if (leftIndex == rightIndex) {
			// Combined branch score.
			score = min(leftDistance, rightDistance) + leftSteps + 1;
		} else {
			// Branch right.
			const uint32_t rightSteps = getSteps(cache, ring, rightIndex, key, keyIndex + 1);
			score = min(leftDistance + leftSteps, rightDistance + rightSteps) + 1;
		}

		// Cache result.
		cache.emplace(cacheLookupValue, score);
		return score;
	}

	int findRotateSteps(string ring, string key) {
		map<uint64_t, uint32_t> cache;
		return getSteps(cache, ring, 0, key, 0);
	}
};
class Solution {
public:
	string kthDistinct(vector<string>& arr, int k) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = arr.size();

		// Scan information.
		int usedIndex = 0;
		unordered_map<string, int> used;

		// Find kth distinct.
		int i;
		for (i = 0; i < n; i++) {
			const string& target = arr[i];

			// Update used map.
			for (; usedIndex < n; usedIndex++) {
				const string& found = arr[usedIndex];
				const auto foundIt = used.find(found);
				if (foundIt == used.end()) {
					// Create entry.
					used.emplace(found, 1);
					continue;
				}

				// Update entry.
				foundIt->second++;

				// We can continue later when we need it.
				if (found == target && foundIt->second > 1) break;
			}

			// Check if target is distinct.
			auto it = used.find(target);
			if (it->second > 1) continue;

			// Count to k.
			k--;
			if (k <= 0) break;
		}
		return i < n ? arr[i] : "";
	}
};
class Solution {
public:
	bool threeConsecutiveOdds(vector<int>& arr) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Find 3 consecutive.
		const int n = arr.size();
		for (int i = 0; i < n; i++) {
			// Skip to next odd.
			while (i < n && (arr[i] & 0b1) == 0b0) i++;

			// Get consecutive count.
			int len = 1;
			while (i + len < n && (arr[i + len] & 0b1) == 0b1 && len < 3) len++;

			// If consecutive long enough, return true.
			if (len >= 3) return true;

			// Move i.
			i += len;
		}

		// Not found.
		return false;
	}
};
class Solution {
public:
	bool checkIfExist(vector<int>& arr) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Naive.
		const int extent = arr.size();
		for (int i = 0; i < extent; i++) {
			const int d = arr[i] * 2;
			for (int j = 0; j < extent; j++) {
				if (i == j) continue;
				if (arr[j] == d) return true;
			}
		}
		// None found.
		return false;
	}
};
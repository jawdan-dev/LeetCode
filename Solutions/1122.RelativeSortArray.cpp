class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Create index map.
		unordered_map<int, int> indexMap;
		for (int i = 0; i < arr2.size(); i++)
			indexMap.emplace(arr2[i], i);

		// Sort by index map.
		sort(arr1.begin(), arr1.end(), [&indexMap](const int a, const int b) {
			auto itb = indexMap.find(b);
			auto ita = indexMap.find(a);

			// Non-indexed cases.
			if (ita == indexMap.end() && itb == indexMap.end()) return a < b;
			if (itb == indexMap.end()) return true;
			if (ita == indexMap.end()) return false;

			// Sort by index.
			return ita->second < itb->second;
		});

		// Return sorted array.
		return arr1;
	}
};
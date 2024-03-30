class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
        // Output storage.
        vector<int> result;

		// Lookup storage.
		map<int, int> dataMap;

		// Find pair.
		for (int i = 0; i < nums.size(); i++) {
			// Get expected pair value.
			const int pairVal = target - nums[i];

			// Check that pair value is in array..
			if (dataMap.find(pairVal) != dataMap.end()) {
				// Pair found, add to result.
				result.emplace_back(dataMap[pairVal]);
                result.emplace_back(i);
                break;
			}

			// Insert data into map.
			dataMap.emplace(nums[i], i);
		}

		// Return result.
		return result;
	}
};
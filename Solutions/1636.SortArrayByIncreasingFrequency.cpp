class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

        // Get frequency map.
        unordered_map<int, int> frequencyMap;
        for (const int n : nums) frequencyMap[n]++;

        // Convert to pair list.
        vector<pair<int,int>> frequencyList(frequencyMap.begin(), frequencyMap.end());

        // Sort.
        sort(frequencyList.begin(), frequencyList.end(), [&](const pair<int,int>& a, const pair<int,int>& b) {
            // Handle based on frequency.
            if (a.second != b.second)
                return a.second < b.second;
            // Handle based on value.
            return a.first > b.first;
        });

        // Create sorted list.
        const int n = frequencyList.size();
        vector<int> sortedNums(nums.size());
        int sortedIndex = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < frequencyList[i].second; j++)
                sortedNums[sortedIndex++] = frequencyList[i].first;

        return sortedNums;
    }
};
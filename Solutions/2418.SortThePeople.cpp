class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

        // Map out names. 
        const int n = min(names.size(), heights.size());
        map<int, string*> nameMap;
        for (int i = 0; i < n; i++) 
            nameMap[heights[i]] = &names[i];

        // Convert back to stirng.
        vector<string> output(nameMap.size());
        int i = 0;
        for (auto it = nameMap.rbegin(); it != nameMap.rend(); it++)
            output[i++] = *it->second;

        return output;
    }
};
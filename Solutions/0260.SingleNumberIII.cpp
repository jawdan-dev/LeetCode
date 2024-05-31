class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Speed thingies.
		ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // Calculation variables.
        const int n = nums.size();

        // Find single numbers.
        set<int> singleNumbers;
        for (int i = 0; i < n; i++) {
            const auto it = singleNumbers.find(nums[i]);

            // First of number found, add to set.
            if (it == singleNumbers.end()) singleNumbers.emplace(nums[i]);

            // Num is a duplicate, remove from set.
            else singleNumbers.erase(it);
        }

        // Return list.
        return vector<int>(singleNumbers.begin(), singleNumbers.end());
    }
};
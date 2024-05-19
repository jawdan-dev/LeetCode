class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // Speed thingies.
		ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // Calculation variables.
        long long total = 0;
        int changedCount = 0, minimumChange = INT_MAX;

        // Find values.
        for (int i = 0; i < nums.size(); i++) {
            const int value = nums[i];
            const int changedValue = value ^ k;

            if (changedValue > value) {
                // Count as changed.
                changedCount++;
                // Update total.
                total += changedValue;
                // Update minimum change.
                minimumChange = min(minimumChange, changedValue - value);
            } else {
                // Update total.
                total += value;
                // Update minimum change.
                minimumChange = min(minimumChange, value - changedValue);
            }
        }

        // Return total count (adjusted if odd).
        return (changedCount % 2 == 0) ? 
            total : 
            (total - minimumChange);
    }
};
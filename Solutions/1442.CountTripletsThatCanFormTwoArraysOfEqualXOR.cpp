class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // Speed thingies.
		ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // Calculation variables.
        const int 
            in = arr.size() - 1,
            kn = arr.size();

        // Get triplet count.
        int count = 0;
        for (int i = 0; i < in; i++) {
            int total = arr[i];

            for (int k = i + 1; k < kn; k++) {
                // Add section to total.
                total ^= arr[k];

                // Valid triplet range.
                if (total == 0) count += k - i;
            }
        }
        return count;
    }
};
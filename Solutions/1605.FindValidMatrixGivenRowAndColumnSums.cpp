class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // Speed thingies.
		ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // Calculation variables.
        const int m = colSum.size(), n = rowSum.size();
        vector<vector<int>> result(n, vector<int>(m, 0));

        // March matrix.
        int left = 0, top = 0;
        while (top < m && left < n) {
            // Get min value.
            const int val = min(rowSum[left], colSum[top]);
            // Add to result.
            result[left][top] = val;
            // Remove from sums.
            colSum[top] -= val;
            rowSum[left] -= val;

            // Move!.
            if (rowSum[left] == 0) left++;
            if (colSum[top] == 0) top++;
        }
        return result;
    }
};
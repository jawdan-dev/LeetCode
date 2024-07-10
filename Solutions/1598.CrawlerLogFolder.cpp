class Solution {
public:
	int minOperations(vector<string>& logs) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Get depth.
		int depth = 0;
		const int n = logs.size();
		for (int i = 0; i < n; i++) {
			if (logs[i] == "./") continue;

			if (logs[i] == "../") {
				if (depth > 0) depth--;
			} else {
				depth++;
			}
		}
		return depth;
	}
};
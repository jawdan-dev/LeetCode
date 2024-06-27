class Solution {
public:
	int findCenter(vector<vector<int>>& edges) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Find first reoccuring node.
		const int n = edges.size();
		unordered_set<int> occuredNodes;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				// Check if reoccuring.
				if (occuredNodes.find(edges[i][j]) != occuredNodes.end())
					return edges[i][j];

				// Node has occured.
				occuredNodes.emplace(edges[i][j]);
			}
		}

		return -1;
	}
};
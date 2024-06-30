

class Solution {
public:

	struct UnionFind { // simple version for UnionFind class
		vector<int> m_root;
		int m_components;

		UnionFind(int n) : m_root(n + 1), m_components(n) {
			iota(m_root.begin(), m_root.end(), 0);
		}

		const int find(int x) {
			if (x == m_root[x]) return x;
			return m_root[x] = find(m_root[x]);
		}

		const bool unificate(int x, int y) {
			// Check x & y.
			x = find(x), y = find(y);
			if (x == y) return 0;

			// Switchies.
			m_root[y] = x;
			m_components--;
			return 1;
		}

		const bool isConnected() const {
			return m_components == 1;
		}
	};

	int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Process type 3 edges first
		UnionFind alice(n), bob(n);
		int edgesNeeded = 0;
		for (vector<int>& e : edges)
			if (e[0] == 3)
				edgesNeeded += alice.unificate(e[1], e[2]) | bob.unificate(e[1], e[2]);

		// Process type 1 and type 2 edges.
		for (vector<int>& e : edges) {
			if (e[0] == 1) edgesNeeded += alice.unificate(e[1], e[2]);
			else if (e[0] == 2) edgesNeeded += bob.unificate(e[1], e[2]);
		}

		// Return edges that can be removed.
		if (alice.isConnected() && bob.isConnected())
			return edges.size() - edgesNeeded;

		// Graph isn't valid.
		return -1;
	}
};
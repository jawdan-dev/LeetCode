class Solution {
public:
    vector<set<int>> ancestors, descendants;

    void updateDescendants(const int ancestor, const int descendant) {
        ancestors[descendant].emplace(ancestor);
        for (int d : descendants[descendant])
            updateDescendants(ancestor, d);
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Speed thingies.
		ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // Reserve memory.
        ancestors.reserve(n);
        descendants.reserve(n);
        for (int i = 0; i < n; i++) {
            ancestors.emplace_back();
            descendants.emplace_back();
        }

        // Assign edges recusively.
        const int e = edges.size();
        for (int i = 0; i < e; i++) {
            // Remember descendant.
            descendants[edges[i][0]].emplace(edges[i][1]);

            // Add self as ancestor.
            updateDescendants(edges[i][0], edges[i][1]);

            // Recurse.
            for (int a : ancestors[edges[i][0]])
                updateDescendants(a, edges[i][1]);
        }

        // Convert to expected data.
        vector<vector<int>> vAncestors(n);
        for (int i = 0; i < n; i++)
            vAncestors[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        return vAncestors;
    }
};
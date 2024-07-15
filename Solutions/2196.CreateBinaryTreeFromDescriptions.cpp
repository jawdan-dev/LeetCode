/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = descriptions.size();
		unordered_map<int, TreeNode*> nodes;
		unordered_set<TreeNode*> missingParents;

		// Build tree.
		for (int i = 0; i < n; i++) {
			// Get data.
			const int
				parent = descriptions[i][0],
				child = descriptions[i][1];
			const bool isLeft = descriptions[i][2] == 1;

			// Get child.
			auto childIt = nodes.find(child);
			if (childIt == nodes.end()) {
				// Create child.
				childIt = nodes.emplace(child, new TreeNode(child)).first;
			} else {
				// Remove child from missing parents set.
				missingParents.erase(missingParents.find(childIt->second));
			}

			// Get parent.
			auto parentIt = nodes.find(parent);
			if (parentIt == nodes.end()) {
				// Create parent.
				parentIt = nodes.emplace(parent, new TreeNode(parent)).first;
				// Unspecified parent, so add to missing parent set.
				missingParents.emplace(parentIt->second);
			}

			// Add child to parent.
			if (isLeft) parentIt->second->left = childIt->second;
			else parentIt->second->right = childIt->second;
		}

		// Last remaining node must be our root.
		return *missingParents.begin();
	}
};
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
	vector<TreeNode*> availableNodes;

	void getSortedList(TreeNode* root) {
		if (root == nullptr) return;

		// Recurse left.
		getSortedList(root->left);

		// Add own node to list.
		availableNodes.emplace_back(root);

		// Recurse right.
		getSortedList(root->right);
	}

	TreeNode* createBalancedTree(const int from, const int to) {
		// Make sure we're searching valid indices.
		if (from > to) return nullptr;

		// Get middle node.
		const int mid = (from + to) / 2;
		TreeNode*& node = availableNodes[mid];

		// Set left and right trees.
		node->left = createBalancedTree(from, mid - 1);
		node->right = createBalancedTree(mid + 1, to);

		// Return working node.
		return node;
	}

	TreeNode* balanceBST(TreeNode* root) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Get sorted node list.
		getSortedList(root);

		// Create balanced tree.
		return createBalancedTree(0, availableNodes.size() - 1);
	}
};
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
	int m_totalValue = 0;

	void createGreaterTreeFromBST(TreeNode* root) {
		if (root == nullptr) return;

		// Start highest.
		createGreaterTreeFromBST(root->right);

		// Update total.
		m_totalValue += root->val;
		root->val = m_totalValue;

		// To lowest.
		createGreaterTreeFromBST(root->left);
	}

	TreeNode* bstToGst(TreeNode* root) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Create the greater tree.
		createGreaterTreeFromBST(root);
		return root;
	}
};
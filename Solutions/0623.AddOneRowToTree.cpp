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
	void addRow(TreeNode* root, const int val, const int depth) {
		// Ignore invalid node.
		if (root == nullptr) return;

		if (depth > 1) {
			// Recurse down.
			addRow(root->left, val, depth - 1);
			addRow(root->right, val, depth - 1);
			return;
		}

		// Insert left.
		TreeNode* newLeft = new TreeNode(val);
		newLeft->left = root->left;
		root->left = newLeft;

		// Insert right.
		TreeNode* newRight = new TreeNode(val);
		newRight->right = root->right;
		root->right = newRight;
	}

	TreeNode* addOneRow(TreeNode* root, int val, int depth) {
		if (depth == 1) {
			// Edge case.
			TreeNode* newRoot = new TreeNode(val);
			newRoot->left = root;
			root = newRoot;
		} else {
			addRow(root, val, depth - 1);
		}
		return root;
	}
};
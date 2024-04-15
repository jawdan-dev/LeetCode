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
	int sumLeaves(TreeNode* root, int parentValue) {
		if (root == nullptr) return 0;

		// Calculate this nodes value.
		const int value = (parentValue * 10) + root->val;

		// Check if leaf.
		if (root->left == nullptr && root->right == nullptr)
			return value;

		// Get child values.
		const int
			leftValue = sumLeaves(root->left, value),
			rightValue = sumLeaves(root->right, value);

		// Sum.
		return leftValue + rightValue;
	}

	int sumNumbers(TreeNode* root) {
		return sumLeaves(root, 0);
	}
};
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
	int sumOfLeftLeaves(TreeNode* root) {
		// Exit case.
		if (root == nullptr) return 0;

		// Get sum.
		int sum = sumOfLeftLeaves(root->right) + sumOfLeftLeaves(root->left);

		// Check for left leaf.
		if (root->left != nullptr &&
			root->left->left == nullptr &&
			root->left->right == nullptr)
			// Add value.
			sum += root->left->val;

		// Return sum.
		return sum;
	}
};
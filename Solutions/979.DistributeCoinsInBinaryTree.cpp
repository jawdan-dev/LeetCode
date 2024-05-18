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
	int distributeCoinsRec(TreeNode* root) {
		if (root == nullptr) return 0;

		const int distribution =
			(root->val - 1) +
			distributeCoinsRec(root->left) +
			distributeCoinsRec(root->right);

		total += abs(distribution);

		return distribution;
	}

	int total = 0;
	int distributeCoins(TreeNode* root) {
		distributeCoinsRec(root);
		return total;
	}
};
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
	bool evaluateTreeRec(TreeNode* root) {
		switch (root->val) {
			case 2: return evaluateTree(root->left) || evaluateTree(root->right);
			case 3: return evaluateTree(root->left) && evaluateTree(root->right);
		}
		return root->val;
	}
	bool evaluateTree(TreeNode* root) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		return evaluateTreeRec(root);
	}
};
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
	string m_activePath = "", m_startPath = "Not found.", m_destPath = "Not found.";
	int m_startValue, m_destValue;

	void findTargetNodes(TreeNode* root) {
		// Check if start.
		if (root->val == m_startValue)
			m_startPath = m_activePath;
		// Check if destination.
		else if (root->val == m_destValue)
			m_destPath = m_activePath;

		// Path to left node.
		if (root->left != nullptr) {
			m_activePath.push_back('L');
			findTargetNodes(root->left);
			m_activePath.pop_back();
		}

		// Path to right node.
		if (root->right != nullptr) {
			m_activePath.push_back('R');
			findTargetNodes(root->right);
			m_activePath.pop_back();
		}
	}

	string getDirections(TreeNode* root, int startValue, int destValue) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Setup variables.
		m_startValue = startValue;
		m_destValue = destValue;

		// Process nodes.
		findTargetNodes(root);

		// Find common depth.
		int commonDepth = 0;
		while (m_startPath[commonDepth] == m_destPath[commonDepth]) commonDepth++;

		// Generate path.
		string startToDestPath = "";
		const int startDepth = m_startPath.size();
		for (int i = commonDepth; i < startDepth; i++)
			startToDestPath.push_back('U');
		startToDestPath += m_destPath.substr(commonDepth);

		// Return path.
		return startToDestPath;
	}
};
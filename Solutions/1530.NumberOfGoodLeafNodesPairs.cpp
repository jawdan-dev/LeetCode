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
	int m_count = 0;

	const vector<int> getCount(TreeNode* root, const int distance) {
		// Not anything.
		if (root == nullptr) return { 0 };
		// Leaf.
		if (root->left == nullptr && root->right == nullptr) return { 1 };

		// Process local count.
		vector<int>
			left = getCount(root->left, distance),
			right = getCount(root->right, distance);
		for (const int x : left)
			for (const int y : right)
				if (x > 0 && y > 0 && x + y <= distance)
					m_count++;

		// Process sides.
		vector<int> ans;
		for (const int x : left)
			if (x > 0 && x < distance)
				ans.push_back(x + 1);
		for (const int x : right)
			if (x > 0 && x < distance)
				ans.push_back(x + 1);

		return ans;
	}

	int countPairs(TreeNode* root, int distance) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Do the thing.
		getCount(root, distance);
		return m_count;
	}
};
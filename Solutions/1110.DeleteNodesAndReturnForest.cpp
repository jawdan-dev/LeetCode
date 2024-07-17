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
    set<int> remainingValues;
    vector<TreeNode*> forest;

    TreeNode* processForest(TreeNode* root, bool hasParent = false) {
        if (root == nullptr) return nullptr;

        // Check if node is to be removed.
        auto it = remainingValues.find(root->val);
        const bool remove = it != remainingValues.end();
        if (remove) remainingValues.erase(it);

        // Add if root and not removed.
        if (!remove && !hasParent) forest.emplace_back(root);

        // Process children.
        root->left = processForest(root->left, !remove);
        root->right = processForest(root->right, !remove);

        // Return valid self / removed pointer.
        return remove ? nullptr : root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // Speed thingies.
		ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // Setup data.
        remainingValues = set<int>(to_delete.begin(), to_delete.end());

        // Get forest (group of trees).
        root = processForest(root);
        return forest;
    }
};
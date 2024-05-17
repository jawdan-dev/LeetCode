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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr) return root;

        // Recurse first.
        if (removeLeafNodes(root->left, target) == nullptr) root->left = nullptr;
        if (removeLeafNodes(root->right, target) == nullptr) root->right = nullptr;

        // Remove target matching leaf.
        if (root->left == nullptr && root->right == nullptr && root->val == target) 
            return nullptr;

        // All good.
        return root;
    }
};
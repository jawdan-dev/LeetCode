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
    const bool compare(const vector<char>& a, const vector<char>& b) {
        const int aSize = a.size(), bSize = b.size();
        const int minSize = min(aSize, bSize);
        for (int i = 1; i <= minSize; i++)
            if (a[aSize - i] != b[bSize - i]) 
                return a[aSize - i] < b[bSize - i];
        return aSize < bSize;
    }

    void traverse(TreeNode* root, vector<char>& currentPath, vector<char>& bestPath) {
        if (root == nullptr) return;

        // Append to current path.
        currentPath.emplace_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            // Handle leaf.
            if (bestPath.empty() || compare(currentPath, bestPath)) 
                bestPath = currentPath;

        } else {
            // Recurse.
            traverse(root->left, currentPath, bestPath);
            traverse(root->right, currentPath, bestPath);
        }

        // Remove from current path.
        currentPath.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        // Get best path.
        vector<char> currentPath, bestPath;
        traverse(root, currentPath, bestPath);

        // Convert to string.
        string output;
        output.reserve(bestPath.size());
        for (int i = bestPath.size() - 1; i >= 0; i--)
            output += 'a' + bestPath[i];

        // Return output string.
        return output;
    }
};
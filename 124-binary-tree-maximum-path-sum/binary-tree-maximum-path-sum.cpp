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
    int maxi = INT_MIN;
    int solve(TreeNode* root) {
        if(!root) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        int both = root->val + l + r;
        int LorR = root->val + max(l, r);
        int node = root->val;
        maxi = max({maxi, LorR, both, node});
        return max(node, LorR);

    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};
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
    pair<int, int> cSum(TreeNode* root) {
        if(!root) return {0,0};

        auto [l, lc] = cSum(root->left);
        auto [r, rc] = cSum(root->right);

        return {root->val + l + r, lc + rc + 1};
    }
    int solve(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;

        auto [sum, cnt] = cSum(root);
        if(sum / cnt == root->val) ans++;
        
        ans += solve(root->left);
        ans += solve(root->right);

        return ans;

    }
    int averageOfSubtree(TreeNode* root) {
        return solve(root);   
    }
};
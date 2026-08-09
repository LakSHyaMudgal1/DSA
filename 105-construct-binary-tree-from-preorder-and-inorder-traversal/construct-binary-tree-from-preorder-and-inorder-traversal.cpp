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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, 
        int start, int end, int& idx) {
            if(start > end) return NULL;

            int rootVal = preorder[idx];
            idx++;
            int i = 0;
            for(i = start; i <= end; i++) {
                if(inorder[i] == rootVal) break;
            }

            TreeNode* root = new TreeNode(rootVal);
            root->left = solve(preorder, inorder, start, i - 1, idx);
            root->right = solve(preorder, inorder, i + 1, end, idx);
            return root;
        }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int n = preorder.size();
        return solve(preorder, inorder, 0, n - 1, idx);
    }
};
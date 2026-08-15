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
    TreeNode* build(vector<int>& A, int& idx, int bound){
        if(idx == A.size() || A[idx] > bound) {
            return NULL;
        }

        int rootVal = A[idx];
        idx++;
        
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(A, idx, root->val);
        root->right = build(A, idx, bound);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& A) {
        int idx = 0;
        return build(A, idx, INT_MAX);
    }
};
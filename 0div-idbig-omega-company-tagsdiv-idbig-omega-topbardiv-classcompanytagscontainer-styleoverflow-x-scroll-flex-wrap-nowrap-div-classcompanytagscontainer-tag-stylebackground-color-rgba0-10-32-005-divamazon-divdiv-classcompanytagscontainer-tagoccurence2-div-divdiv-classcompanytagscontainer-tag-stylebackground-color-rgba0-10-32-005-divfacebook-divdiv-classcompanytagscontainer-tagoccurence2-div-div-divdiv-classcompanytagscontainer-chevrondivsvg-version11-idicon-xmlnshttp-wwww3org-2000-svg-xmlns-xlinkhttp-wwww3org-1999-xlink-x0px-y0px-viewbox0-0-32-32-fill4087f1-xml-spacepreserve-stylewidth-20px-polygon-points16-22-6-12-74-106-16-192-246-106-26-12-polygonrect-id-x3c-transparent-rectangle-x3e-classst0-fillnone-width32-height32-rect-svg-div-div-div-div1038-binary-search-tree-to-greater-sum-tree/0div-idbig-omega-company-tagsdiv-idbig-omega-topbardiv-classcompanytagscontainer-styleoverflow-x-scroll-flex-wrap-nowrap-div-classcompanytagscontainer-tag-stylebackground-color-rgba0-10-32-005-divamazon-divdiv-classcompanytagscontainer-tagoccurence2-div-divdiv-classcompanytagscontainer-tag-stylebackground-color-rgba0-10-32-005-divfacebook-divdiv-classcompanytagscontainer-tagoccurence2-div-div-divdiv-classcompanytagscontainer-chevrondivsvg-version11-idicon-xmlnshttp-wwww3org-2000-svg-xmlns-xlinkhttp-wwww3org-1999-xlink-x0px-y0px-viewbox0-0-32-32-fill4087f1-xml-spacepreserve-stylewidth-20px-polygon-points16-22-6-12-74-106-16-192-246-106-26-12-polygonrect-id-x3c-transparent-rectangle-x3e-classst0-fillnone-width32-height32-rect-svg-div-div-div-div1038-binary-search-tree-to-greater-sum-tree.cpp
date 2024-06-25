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
    void dfs(TreeNode* root, int &maxi) { //right->root->left
        if(root == NULL) return;
        dfs(root->right, maxi);
        root->val = root->val+maxi;
        maxi = max(maxi,root->val);
        dfs(root->left, maxi);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int maxi = 0;
        dfs(root, maxi);
        return root;
    }
};
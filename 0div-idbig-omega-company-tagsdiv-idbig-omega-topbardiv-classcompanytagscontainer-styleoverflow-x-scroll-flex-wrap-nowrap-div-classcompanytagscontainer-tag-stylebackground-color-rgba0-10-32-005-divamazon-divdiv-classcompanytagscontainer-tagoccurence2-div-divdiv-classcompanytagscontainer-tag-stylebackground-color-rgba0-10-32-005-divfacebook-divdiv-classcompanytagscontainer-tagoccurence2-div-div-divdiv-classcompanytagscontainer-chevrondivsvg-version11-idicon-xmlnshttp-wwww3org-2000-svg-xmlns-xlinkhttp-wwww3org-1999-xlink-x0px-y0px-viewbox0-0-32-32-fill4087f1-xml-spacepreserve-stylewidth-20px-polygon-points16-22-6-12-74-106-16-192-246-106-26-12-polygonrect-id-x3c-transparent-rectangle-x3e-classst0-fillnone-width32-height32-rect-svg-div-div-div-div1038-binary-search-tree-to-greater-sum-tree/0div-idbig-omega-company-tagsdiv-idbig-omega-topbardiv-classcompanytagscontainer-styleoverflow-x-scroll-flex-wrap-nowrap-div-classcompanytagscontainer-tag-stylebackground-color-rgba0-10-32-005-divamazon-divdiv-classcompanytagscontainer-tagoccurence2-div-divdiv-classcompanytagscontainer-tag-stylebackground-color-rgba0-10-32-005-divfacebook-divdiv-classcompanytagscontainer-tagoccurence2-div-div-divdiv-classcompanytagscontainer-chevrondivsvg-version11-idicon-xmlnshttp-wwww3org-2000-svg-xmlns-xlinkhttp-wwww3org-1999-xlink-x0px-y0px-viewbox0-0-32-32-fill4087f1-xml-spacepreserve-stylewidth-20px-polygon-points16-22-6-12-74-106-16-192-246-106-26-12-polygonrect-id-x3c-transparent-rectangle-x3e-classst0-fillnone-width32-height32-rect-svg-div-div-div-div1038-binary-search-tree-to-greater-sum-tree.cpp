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
    void dfs(TreeNode* root, int &sum) { //right->root->left
        if(root == NULL) return;
        dfs(root->right, sum);
        sum += root->val;
        root->val = sum; //update root node with the sum received from right subtree
        dfs(root->left, sum);
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        // reverse inorder traversal, TC: O(n), SC: O(n)
        int sum = 0;
        dfs(root, sum);
        return root;
    }
};
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
    int sumOfLeftLeaves(TreeNode* root) {
        // TC: O(N), SC: O(N)
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            
            if(front != NULL) {
                if(front->left != NULL) {
                    if(front->left->left == NULL && front->left->right == NULL) { //if left child is leaf node, then only include it in sum
                        sum += front->left->val;
                    }
                    q.push(front->left);
                }
                if(front->right != NULL) {
                    q.push(front->right);
                }
            }
        }
        
        return sum;
    }
};
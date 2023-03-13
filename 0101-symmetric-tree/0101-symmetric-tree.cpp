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
    bool helper(TreeNode* leftSubtree, TreeNode* rightSubtree) {
        if(leftSubtree == NULL || rightSubtree == NULL) {
            return leftSubtree == rightSubtree; 
        }    
        
        if(leftSubtree->val != rightSubtree->val) {
            return false;
        }
        
        return helper(leftSubtree->left, rightSubtree->right) && helper(leftSubtree->right, rightSubtree->left);
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return false;
        return helper(root->left, root->right);
    }
};
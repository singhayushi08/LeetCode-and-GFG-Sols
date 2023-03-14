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
    void helper(TreeNode* root, int &sum, string &s) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            s += root->val + '0';
            sum += stoi(s);
            return;
        }    
        
        s += root->val + '0';
        helper(root->left, sum, s);
        if(root->left != NULL) s.pop_back();
        helper(root->right, sum, s);
        if(root->right != NULL) s.pop_back();
    }
    
    void solve(TreeNode* root, int &sum, int temp) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            temp = temp*10 + root->val;
            sum += temp;
            return;
        }
        
        temp = temp*10 + root->val;
        solve(root->left, sum, temp);
        solve(root->right, sum, temp);
    }
    
    
public:
    int sumNumbers(TreeNode* root) {
        // using string and then converting into num to add in sum, TC: O(N), SC: O(H)
        // string s = "";
        // int sum = 0;
        // helper(root, sum, s);
        // return sum;
        
        // Using num directly, TC: O(N), SC: O(H)
        int sum = 0;
        int temp = 0;
        solve(root,sum,temp);
        return sum; 
        
    }
};
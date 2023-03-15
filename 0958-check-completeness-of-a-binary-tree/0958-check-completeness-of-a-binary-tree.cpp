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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL || (!root->left && !root->right)) return true;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.front() != NULL) {
            TreeNode* front = q.front();
            q.pop();

            q.push(front->left);
            q.push(front->right);
        }
        
        while(!q.empty()) { //if any node found after finding a null in queue, then it is not CBT
            TreeNode* f = q.front();
            q.pop();
            if(f != NULL) return false;
        }
        
        return true;
    }
};
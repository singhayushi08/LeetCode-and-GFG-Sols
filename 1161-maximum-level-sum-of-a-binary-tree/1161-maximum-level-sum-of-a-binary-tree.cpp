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
    int maxLevelSum(TreeNode* root) {
        // BFS in Binary tree, TC: O(N), SC: O(N)
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0, maxSum = INT_MIN;
        
        while(!q.empty()) {
            level++;
            // cout<<"level : "<<level<<endl;
            int sum = 0;
            int size = q.size();
            for(int i=0; i<size; i++) { // iterate over the nodes of current level in q
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            // cout<<"sum : "<<sum<<endl;
            if(sum > maxSum) {
                maxSum = sum;
                ans = level;
            }
            // cout<<"maxSum: "<<maxSum<<endl;
        }
        
        return ans;
    }
};
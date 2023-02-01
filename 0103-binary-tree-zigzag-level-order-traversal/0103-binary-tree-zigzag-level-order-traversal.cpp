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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         // using two stacks
//         // TC: O(N), SC: O(N) coz both stacks together will have N nodes
        
//         vector<vector<int>> ans;
//         if(root == NULL) return ans;
//         stack<TreeNode*> right_to_left; //we need 0th level to be left to right, so we use the opposite
//         stack<TreeNode*> left_to_right; //the next level has to be reverse i.e. right to left, so we use the opposite
//         right_to_left.push(root);
        
//         while(right_to_left.size() != 0 || left_to_right.size() != 0) {
            
//             // normal order (L to R)
//             vector<int> v1;
//             while(right_to_left.size() != 0) {
//                 TreeNode* top1 = right_to_left.top();
//                 right_to_left.pop();
//                 v1.push_back(top1->val);
            
//                 if(top1 -> left != NULL) {
//                     left_to_right.push(top1->left);
//                 }
//                 if(top1 -> right != NULL) {
//                     left_to_right.push(top1->right);
//                 }
//             }
//             if(!v1.empty()) ans.push_back(v1);
            
//             // reverse order (R to L)
//             vector<int> v2;
//             while(left_to_right.size() != 0) {
//                 TreeNode* top2 = left_to_right.top();
//                 left_to_right.pop();
//                 v2.push_back(top2->val);
                
//                 if(top2 -> right != NULL) {
//                     right_to_left.push(top2->right);
//                 }
//                 if(top2 -> left != NULL) {
//                     right_to_left.push(top2->left);
//                 }
//             }
//             if(!v2.empty()) ans.push_back(v2);
//         }
        
//         return ans;
        
        // Using queue, TC: O(N), SC: O(N)
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool left_to_right = true; 
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> level(size);  // to store curr level
            for(int i=0; i<size; i++) {
                TreeNode* front = q.front();
                q.pop();
                int index = (left_to_right == true) ? i : size-i-1;
                level[index] = front->val;
                
                if(front->left != NULL) {
                    q.push(front->left);
                }
                if(front->right != NULL) {
                    q.push(front->right);
                }
            }
            //now curr level is over
            left_to_right = !left_to_right; //change the bool
            ans.push_back(level);
        }
        
        return ans;
        
    }
};
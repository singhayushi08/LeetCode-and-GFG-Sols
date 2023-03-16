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
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder, int poS, int poE, int inS, int inE) {
        if(poS > poE || inS > inE) {
            return NULL;
        }
        int rootData = postorder[poE];
        int lpoS = poS;
        int linS = inS;

        int rootIndex;
        for(int i = inS; i<= inE; i++) {
            if(inorder[i] == rootData) {
                rootIndex = i;
                break;
            }
        }
        int linE = rootIndex - 1;
        int lpoE = linE - linS + lpoS;
        int rpoS = lpoE + 1;
        int rpoE = poE - 1;
        int rinS = rootIndex + 1;
        int rinE = inE;

        TreeNode* root = new TreeNode(rootData);
        root->left = helper(postorder, inorder, lpoS, lpoE, linS, linE);
        root->right = helper(postorder, inorder, rpoS, rpoE, rinS, rinE);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size(); //same size as postorder obvio
        return helper(postorder, inorder, 0, size-1, 0, size-1);
    }
};
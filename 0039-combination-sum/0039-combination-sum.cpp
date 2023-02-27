class Solution {
    void helper(int idx, vector<int> &candidates, int n, vector<int> v, vector<vector<int>> &ans, int target) {
        if(idx == n) { // base case
            if(target == 0) { //condition is satisfied
                ans.push_back(v); // push_back creates a copy of the argument object
            } 
            return; 
        }

        // pick this element at idx
        if(candidates[idx] <= target) {
            v.push_back(candidates[idx]);
            helper(idx, candidates, n, v, ans, target-candidates[idx]); //do not change idx coz we may pick it again
            v.pop_back();
        }

        // not pick this element
        helper(idx+1, candidates, n, v, ans, target);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // TC: exponential(2^target*k) where avg length of combination is k, SC: O(k*x) where x is no. of combinations
        vector<vector<int>> ans;
        vector<int> v;
        int n = candidates.size();
        helper(0, candidates, n, v, ans, target);
        return ans;
    }
};
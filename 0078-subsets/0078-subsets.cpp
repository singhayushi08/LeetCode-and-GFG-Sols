class Solution {
    void helper(int idx, vector<int>& nums, vector<int> v, vector<vector<int>> &ans) {
        if(idx == nums.size()) {
            ans.push_back(v);
            return;
        }

        // pick this element
        v.push_back(nums[idx]);
        helper(idx+1, nums, v, ans);
        v.pop_back();

        // not pick
        helper(idx+1, nums, v, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Recursion, TC: O(2^n), SC: O(n) for rec stack space
        vector<vector<int>> ans;
        vector<int> v;
        helper(0,nums,v,ans);
        return ans;
    }
};
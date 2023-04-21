class Solution {
    void f(int idx, int prev_idx, vector<int>& nums, vector<int>& temp, set<vector<int>> &ans) {
        if(idx == nums.size()) {
            if(temp.size() >= 2) ans.insert(temp);
            return;
        }
        
        // not pick
        f(idx+1, prev_idx, nums, temp, ans);
        // pick
        if(prev_idx == -1 || nums[idx] >= nums[prev_idx]) {
            temp.push_back(nums[idx]);
            f(idx+1, idx, nums, temp, ans);
            temp.pop_back();
        }
    }
    
    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // TC: O(2^n * n), SC: O(n) does not give tle coz input is very small
        set<vector<int>> ans;
        vector<int> temp;
        f(0, -1, nums, temp, ans);
        // convert set into 2d vector
        vector<vector<int>> v;
        v.assign(ans.begin(), ans.end());
        return v;
    }
};
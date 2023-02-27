class Solution {
    void helper(int idx, vector<int> &nums, vector<int> v, set<vector<int>> &s) {
        if(idx == nums.size()) {
            sort(v.begin(), v.end()); //we want each subset to be sorted
            s.insert(v);
            return;
        }

        // pick this element
        v.push_back(nums[idx]);
        helper(idx+1, nums, v, s);
        v.pop_back();

        // not pick
        helper(idx+1, nums, v, s);
    }

    void findSubsets(int idx, vector<int>& nums, vector<int> &v, vector<vector<int>> &ans) {
        if(idx == nums.size()) { //base case
            ans.push_back(v);
            return;
        }
        ans.push_back(v);
        for(int i=idx; i<nums.size(); i++) {
            if(i != idx && nums[i] == nums[i-1]) continue; //skip duplicate
            v.push_back(nums[i]);
            findSubsets(i+1, nums, v, ans);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Brute using recursion
        // generate all possible subsets and store in hashset to get unique subsets only
        // set<vector<int>> s;
        // vector<int> v;
        // helper(0,nums,v,s);
        // // convert set back into 2d vector
        // vector<vector<int>> ans;
        // ans.assign(s.begin(),s.end());
        // return ans;

        // Subsequence approach
        // TC: O(nlogn for sorting + 2^n*k) = O(2^n*k), SC: O(2^n*k + n for rec) = O(2^n*k) where k is avg length of subset
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        findSubsets(0,nums,v,ans);
        return ans;
    }
};
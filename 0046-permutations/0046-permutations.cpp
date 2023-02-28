class Solution {
    void helper(vector<int>& nums, unordered_map<int,int> &mp, vector<int> v, vector<vector<int>> &ans) {
        //base case
        if(v.size() == nums.size()) {
            ans.push_back(v);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            if(mp[nums[i]] == 0) { //if this element is not present in our curr permutation, then take this
                v.push_back(nums[i]);
                mp[nums[i]] = 1; //mark visited
                helper(nums, mp, v,ans);
                v.pop_back(); //remove from ans while backtracking
                mp[nums[i]] = 0; //unmark
            }
        }
    }

    void findPermutations(int idx, vector<int> &nums, vector<vector<int>> &ans) {
        // base case
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i=idx; i<nums.size(); i++) {
            swap(nums[idx], nums[i]);
            findPermutations(idx+1, nums, ans);
            swap(nums[idx], nums[i]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Approach 1=> uses extra space to use hashmap/array
        // TC: O(n*n!) where n! is for finding all possible permutations and n for traversing over the map to check if present/not present, SC: O(n) for map + O(n) for rec stack space + O(n) for vector v => SC: O(n)
        // vector<vector<int>> ans;
        // vector<int> v; //to store curr permutation
        // unordered_map<int,int> mp; //key=> curr element, value=> 1 if present, 0 if not present in curr permutation
        // for(auto i: nums) {
        //     mp[i] = 0;
        // }
        // helper(nums, mp, v, ans);
        // return ans;

        // Approach 2-> No extra space, just swapping to put curr element at every index
        // TC: O(n!*n), SC: O(n) only for rec stack space
        vector<vector<int>> ans;
        findPermutations(0, nums, ans);
        return ans;
    }
};
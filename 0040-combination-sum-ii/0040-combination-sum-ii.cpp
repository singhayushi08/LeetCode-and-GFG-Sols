class Solution {
    void helper(int idx, vector<int>& candidates, int target, vector<int> &v, set<vector<int>> &s) {
        if(idx == candidates.size()) {
            if(target == 0) {
                s.insert(v); 
            }
            return;
        }

        // pick this element
        if(candidates[idx] <= target) {
            v.push_back(candidates[idx]);
            helper(idx+1, candidates, target-candidates[idx], v, s); //same code as combination sum I, except for idx+1 here
            v.pop_back();
        }
        
        // not pick
        helper(idx+1, candidates, target, v, s);
    }

    void findCombinations(int idx,vector<int>& candidates, int target, vector<int> v, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(v);
            return;
        }
        
        for(int i=idx; i<=candidates.size()-1; i++) {
            if(i > idx && candidates[i] == candidates[i-1]) continue; //to avoid duplicates
            if(candidates[i] > target) break; //cannot pick this element
            v.push_back(candidates[i]);
            findCombinations(i+1,candidates,target-candidates[i],v,ans);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Brute force (pick/not pick approach) => gives TLE
        // TC: O(2^t*k + nlogn) where t is target and k is avg length of combination
        // SC: O(k*x*logn) where is x is no. of combinations, logn for putting vector v in set s
        // sort(candidates.begin(), candidates.end()); //coz we need ans in sorted order
        // set<vector<int>> s; //to avoid duplicates
        // vector<int> v;
        // helper(0,candidates,target,v,s);
        // //convert this set back into 2d vector, this takes extra tc O(N) and sc O(N)
        // vector<vector<int>> ans;
        // ans.assign(s.begin(),s.end());
        // return ans;

        // Subsequence approach, TC: O(2^n*k), SC: O(k*x)
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        findCombinations(0,candidates,target,v,ans);
        return ans;

    }
};
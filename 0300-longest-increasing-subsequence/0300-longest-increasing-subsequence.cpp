class Solution {
    int f(int idx, int prev_idx, vector<int>& nums, vector<vector<int>> &dp) { // f(0,-1) signifies max length of lis starting from idx 0 and previdx as -1
        if(idx == nums.size()) return 0;    
        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1]; 
        
        int notTake = 0 + f(idx+1, prev_idx, nums, dp);
        int take = 0;
        if(prev_idx == -1 || nums[idx] > nums[prev_idx]) {
            take = 1 + f(idx+1, idx, nums, dp);
        }
        
        return dp[idx][prev_idx+1] = max(take, notTake);
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {        
        // Memoization
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return f(0, -1, nums, dp);
        
        // Tabulation
//         vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
//         for(int idx=n-1; idx>=0; idx--) {
//             for(int prev_idx=idx-1; prev_idx>=-1; prev_idx--) {
//                 int notTake = 0 + dp[idx+1][prev_idx+1];
//                 int take = 0;
//                 if(prev_idx == -1 || nums[idx] > nums[prev_idx]) {
//                     take = 1 + dp[idx+1][idx+1];
//                 }

//                 dp[idx][prev_idx+1] = max(take, notTake);
//             }
//         }

//         return dp[0][-1+1];
        
        // Space Optimised
        vector<int> next(n+1, 0), curr(n+1, 0);
        
        for(int idx=n-1; idx>=0; idx--) {
            for(int prev_idx=idx-1; prev_idx>=-1; prev_idx--) {
                int notTake = 0 + next[prev_idx+1];
                int take = 0;
                if(prev_idx == -1 || nums[idx] > nums[prev_idx]) {
                    take = 1 + next[idx+1];
                }

                curr[prev_idx+1] = max(take, notTake);
            }
            next = curr;
        }

        return next[-1+1];
    }
};
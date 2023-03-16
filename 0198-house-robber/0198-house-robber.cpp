class Solution {
    int f(int idx, vector<int> &nums) { 
        //f(n-1) signifies the max amount of money you can rob from 0 to n-1 with no two adjacent houses
        if(idx == 0) return nums[0]; 
        if(idx < 0) return 0;
        
        int pick = nums[idx] + f(idx - 2, nums);
        int notPick = 0 + f(idx - 1, nums);
        
        return max(pick, notPick);
    }
    
    
    int memo(int idx, vector<int> &nums, vector<int> &dp) {
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int pick = nums[idx] + memo(idx - 2, nums, dp);
        int notPick = 0 + memo(idx - 1, nums, dp);
        
        return dp[idx] = max(pick, notPick);
    }
    
public:
    int rob(vector<int>& nums) {
        // ques is same as: find max sum of non-adjacent elements 
        int n = nums.size();
        
        // Recursion, TC: O(2^n), SC: O(2^n)
        // return f(n-1, nums);
        
        // Memoization, TC: O(n), SC: O(2n)
        vector<int> dp(n,-1);
        return memo(n-1, nums, dp);
        
        
        
    }
};
class Solution {
    int f(int idx, vector<int> &nums) { 
        //f(n-1) signifies the max amount of money you can rob from 0 to n-1 with no two adjacent houses
        
        if(idx == 0) return nums[0];  //you can only come to 0 when you did not pick 1, so now you can pick 0th element 
        if(idx < 0) return 0; 
        
        int pick = nums[idx] + f(idx-2, nums); //if you have picked i then you cannot pick i-1(coz they are adjacent)
        int notPick = 0 + f(idx-1, nums); //if you dont pick i, then move to i-1
        
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
        // vector<int> dp(n,-1);
        // return memo(n-1, nums, dp);
        
        // Tabulation, TC: O(n), SC: O(1)
//         vector<int> dp(n);
//         dp[0] = nums[0];
        
//         for(int i=1; i<n; i++) {
//             int pick = nums[i];
//             if(i >= 2) pick += dp[i-2];
//             int notPick = 0 + dp[i-1];
            
//             dp[i] = max(pick, notPick);
//         }
        
//         return dp[n-1];
        
        // Space Optimisation, TC: O(n), SC: O(1)
        int prev1 = nums[0];
        int prev2 = 0;
        
        for(int i=1; i<n; i++) {
            int pick = nums[i];
            if(i >= 2) pick += prev2;
            int notPick = 0 + prev1;
            
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
        
        
        
        
        
    }
};
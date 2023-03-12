class Solution {
    int helper(int n, vector<int> &dp) {
        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = helper(n-1, dp) + helper(n-2, dp);
    }
    
public:
    int climbStairs(int n) {
        // Recursion, TC: O(2^n), SC: O(n)
        // if(n == 0 || n == 1) return 1;
        // return climbStairs(n-1) + climbStairs(n-2);
        
        // Memoization, TC: O(N), SC: O(2N) where O(N) is for rec stack space and O(N) for using 1d array 
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};
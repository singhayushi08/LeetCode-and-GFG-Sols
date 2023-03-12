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
        // vector<int> dp(n+1, -1);
        // return helper(n, dp);
        
        // Tabulation, TC: O(N), SC: O(N) only for array
        // vector<int> dp(n+1);
        // dp[0] = 1;
        // dp[1] = 1;
        // for(int i=2; i<=n; i++) {
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];
        
        // Space Optimised, TC: O(N), Sc: O(1)
        int a = 1, b = 1, c;
        for(int i=2; i<=n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
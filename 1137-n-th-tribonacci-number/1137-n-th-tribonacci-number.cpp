class Solution {
    int trib(int n, vector<int> &dp) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        
        if(dp[n] != -1) {
            return dp[n];
        }
        
        return dp[n] = trib(n-1, dp) + trib(n-2, dp) + trib(n-3, dp);
    }
    
public:
    int tribonacci(int n) {
        // Recursion, TC: O(3^n), SC: O(n)
//         if(n == 0) return 0;
//         if(n == 1 || n == 2) return 1;
        
//         return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        
        // Memoization, TC: O(n), SC: O(2n) for array and rec stack space
        vector<int> dp(n+1, -1);
        return trib(n, dp);
        
    }
};
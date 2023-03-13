class Solution {
    int solve(vector<int>& cost, int n) {
        if(n == 0 || n == 1) { //base case
            return cost[n];
        }    
        
        return cost[n] + min(solve(cost, n-1), solve(cost, n-2));
    }
    
    int memo(vector<int>& cost, vector<int> &dp, int n) {
        if(n == 0 || n == 1) {
            return cost[n];
        }
        
        if(dp[n] != -1) {
            return dp[n];
        }
        
        return dp[n] = cost[n] + min(memo(cost, dp, n-1), memo(cost, dp, n-2));
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Recursion, TC: O(2^n), SC: O(n)
        // int n = cost.size();
        // int ans = min(solve(cost, n-1), solve(cost, n-2)); //starting can be 0th idx or 1st idx
        // return ans;
        
        // Memoization, TC: O(n), SC: O(2n) for array and rec stack
        int n = cost.size();
        vector<int> dp(n+1, -1);
        memo(cost, dp, n-1);
        int ans = min(memo(cost,dp,n-1), memo(cost,dp,n-2));
        return ans;
        
    }
};
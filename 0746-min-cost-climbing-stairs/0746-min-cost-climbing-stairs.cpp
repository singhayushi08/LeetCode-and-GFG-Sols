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
        
        // Memoization
        int n = cost.size();
        vector<int> dp(n+1, -1);
        memo(cost, dp, n-1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        return min(dp[n-1], dp[n-2]);
        
    }
};
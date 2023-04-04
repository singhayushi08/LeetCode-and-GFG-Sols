class Solution {
    int f(int idx, int target, vector<int>& coins) {
        if(idx == 0) {
            if(target % coins[0] == 0) return 1;
            else return 0;
        }
        
        int notPick = f(idx-1, target, coins);
        int pick = 0;
        if(coins[idx] <= target) 
            pick = f(idx, target-coins[idx], coins);
        
        return pick + notPick;
    }
    
    int memo(int idx, int target, vector<int>& coins, vector<vector<int>> &dp) {
        if(idx == 0) {
            if(target % coins[0] == 0) return 1;
            else return 0;
        }
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int notPick = memo(idx-1, target, coins, dp);
        int pick = 0;
        if(coins[idx] <= target) 
            pick = memo(idx, target-coins[idx], coins, dp);
        
        return dp[idx][target] = pick + notPick;
    }
   
    
public:
    int change(int amount, vector<int>& coins) {
        // Recursion, TC: O(2^n), SC: O(n)
        int n = coins.size();
        // return f(n-1, amount, coins);
        
        // Memoization, TC: O(n*amount), SC: O(n*amount + n) 
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return memo(n-1, amount, coins, dp);
    }
};
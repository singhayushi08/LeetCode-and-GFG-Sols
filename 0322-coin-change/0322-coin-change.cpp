class Solution {
    
    int f(int idx, int target, vector<int>& coins) {
        if(idx == 0) { 
            if(target%coins[idx] == 0) return target/coins[idx];
            else return 1e8;
        }    
        
        int notPick = 0 + f(idx-1, target, coins); // do not pick a coin => add 0 coins
        int pick = INT_MAX; // pick a coin => add 1 coins
        if(coins[idx] <= target) 
            pick = 1 + f(idx, target-coins[idx], coins);
        
        return min(pick, notPick);
    }
    
    int memo(int idx, int target, vector<int>& coins, vector<vector<int>> &dp) {
        if(idx == 0) { 
            if(target%coins[idx] == 0) return target/coins[idx];
            else return 1e8;
        }    
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int notPick = 0 + memo(idx-1, target, coins, dp); 
        int pick = INT_MAX; 
        if(coins[idx] <= target) 
            pick = 1 + memo(idx, target-coins[idx], coins, dp);
        
        return dp[idx][target] = min(pick, notPick);
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        // Recursion, TC: O(2^n), SC: O(n)
        // int n = coins.size();
        // int ans = f(n-1, amount, coins);
        // if(ans >= 1e8) return -1;
        // return ans;
        
        // Memoization, TC: O(n), SC: O(n*target + n) for 2d array and aux stack space
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = memo(n-1, amount, coins, dp);
        if(ans >= 1e8) return -1;
        return ans;
    }
};
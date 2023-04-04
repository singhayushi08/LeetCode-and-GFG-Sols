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
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // return memo(n-1, amount, coins, dp);
        
        // Tabulation, TC: O(n*amount), SC: O(n*amount)
//         vector<vector<int>> dp(n, vector<int>(amount+1, 0));
//         for(int t=0; t<=amount; t++) {
//             if(t % coins[0] == 0) dp[0][t] = 1;
//             else dp[0][t] = 0;
//         }
        
//         for(int idx=1; idx<n; idx++) {
//             for(int target=0; target<=amount; target++) {
//                 int notPick = dp[idx-1][target]; 
//                 int pick = 0;
//                 if(coins[idx] <= target) 
//                     pick = dp[idx][target-coins[idx]]; 

//                 dp[idx][target] = pick + notPick;
//             }
//         }
        
//         return dp[n-1][amount];
        
        // Space Optimised, TC: O(n*amount), SC: O(amount)
        vector<int> prev(amount+1, 0), curr(amount+1, 0);
        for(int t=0; t<=amount; t++) {
            if(t % coins[0] == 0) prev[t] = 1;
        }
        
        for(int idx=1; idx<n; idx++) {
            for(int target=0; target<=amount; target++) {
                int notPick = prev[target]; 
                int pick = 0;
                if(coins[idx] <= target) 
                    pick = curr[target-coins[idx]]; 

                curr[target] = pick + notPick;
            }
            prev = curr;
        }
        
        return prev[amount];
    }
};
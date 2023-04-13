class Solution {
    int f(int idx, int buy, vector<int>& prices) { // buy = 1 means you can buy a stock, buy = 0 means time to sell
        if(idx == prices.size()) return 0; // base case
        
        int profit;
        if(buy == 1) {
            int buyy = -prices[idx] + f(idx+1, 0, prices); 
            int notBuy = 0 + f(idx+1, 1, prices); 
            profit = max(buyy, notBuy);
        }
        else {
            int sell = prices[idx] + f(idx+1, 1, prices);
            int notSell = 0 + f(idx+1, 0, prices);
            profit = max(sell, notSell);
        }
        
        return profit;
    }
    
    int memo(int idx, int buy, vector<int>& prices, vector<vector<int>> &dp) { 
        if(idx == prices.size()) return 0; // base case
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        int profit;
        if(buy == 1) {
            int buyy = -prices[idx] + memo(idx+1, 0, prices, dp); 
            int notBuy = 0 + memo(idx+1, 1, prices, dp); 
            profit = max(buyy, notBuy);
        }
        else {
            int sell = prices[idx] + memo(idx+1, 1, prices, dp);
            int notSell = 0 + memo(idx+1, 0, prices, dp);
            profit = max(sell, notSell);
        }
        
        return dp[idx][buy] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        
        // Greedy, buy when price is low and sell when high, TC: O(N), SC: O(1)
        // int profit = 0;
        // for(int i=1; i<prices.size(); i++) {
        //     if(prices[i] > prices[i-1]) { // if curr price is greater than the last price, you have some profit
        //         profit += prices[i] - prices[i-1];
        //     }
        // }
        // return profit;
        
        // Recursion,  TC: exponential, SC: O(N) 
         // return f(0, 1, prices);
        
        // Memoization, TC: O(N*2), SC: O(N*2 + N) 
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return memo(0,1,prices,dp);
    }
     
};
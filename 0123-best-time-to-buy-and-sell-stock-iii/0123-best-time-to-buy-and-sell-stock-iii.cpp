class Solution {
    int f(int idx, int buy, int k, vector<int>& prices) { // buy == 1 means you can buy, buy == 0 means time to sell
        if(k == 0) return 0;
        if(idx == prices.size()) return 0;
        
        int profit = 0;
        if(buy == 1) {
            int buyy = -prices[idx] + f(idx+1, 0, k, prices);
            int notBuy = 0 + f(idx+1, 1, k, prices);
            profit = max(buyy, notBuy);
        } 
        else {
            int sell = prices[idx] + f(idx+1, 1, k-1, prices); //transaction is complete when buy and sell, so k-1
            int notSell = 0 + f(idx+1, 0, k, prices);
            profit = max(sell, notSell);
        }
        
        return profit;
    }
    
    int memo(int idx, int buy, int k, vector<int>& prices, vector<vector<vector<int>>> &dp) { 
        if(k == 0) return 0;
        if(idx == prices.size()) return 0;
        
        if(dp[idx][buy][k] != -1) return dp[idx][buy][k];
        
        int profit = 0;
        if(buy == 1) {
            int buyy = -prices[idx] + memo(idx+1, 0, k, prices, dp);
            int notBuy = 0 + memo(idx+1, 1, k, prices, dp);
            profit = max(buyy, notBuy);
        } 
        else {
            int sell = prices[idx] + memo(idx+1, 1, k-1, prices, dp); //transaction is complete when buy and sell, so k-1
            int notSell = 0 + memo(idx+1, 0, k, prices, dp);
            profit = max(sell, notSell);
        }
        
        return dp[idx][buy][k] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        // Recursion
        // return f(0, 1, 2, prices);
        
        // Memo
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return memo(0, 1, 2, prices, dp);
    }
};
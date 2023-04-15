class Solution {
    int f(int idx, int buy, vector<int>& prices, int fee, vector<vector<int>> &dp) {
        if(idx == prices.size()) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        if(buy == 1) { // buy
            int buyy = -prices[idx] + f(idx+1, 0, prices, fee, dp);
            int notBuy = 0 + f(idx+1, 1, prices, fee, dp);
            return dp[idx][buy] = max(buyy, notBuy);
        }
        else { // sell
            int sell = prices[idx] - fee + f(idx+1, 1, prices, fee, dp); //1 transaction is complete, now pay the fee
            int notSell = 0 + f(idx+1, 0, prices, fee, dp);
            return dp[idx][buy] = max(sell, notSell);
        }
    }
    
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return f(0, 1, prices, fee, dp);
        
        // Tabulation
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int idx=n-1; idx>=0; idx--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy == 1) { // buy
                    int buyy = -prices[idx] + dp[idx+1][0];
                    int notBuy = 0 + dp[idx+1][1];
                    dp[idx][buy] = max(buyy, notBuy);
                }
                else { // sell
                    int sell = prices[idx] - fee + dp[idx+1][1]; //1 transaction is complete, now pay the fee
                    int notSell = 0 + dp[idx+1][0];
                    dp[idx][buy] = max(sell, notSell);
                }
            }
        }
        
        return dp[0][1];

    }
};
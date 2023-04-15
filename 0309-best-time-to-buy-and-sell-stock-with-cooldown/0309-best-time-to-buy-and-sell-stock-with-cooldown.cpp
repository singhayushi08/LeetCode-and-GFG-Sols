class Solution {
    int f(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if(idx >= prices.size()) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        if(buy == 1) {
            int buyy = -prices[idx] + f(idx+1, 0, prices, dp);
            int notBuy = 0 + f(idx+1, 1, prices, dp);
            return dp[idx][buy] = max(buyy, notBuy);
        } 
        else {
            int sell = prices[idx] + f(idx+2, 1, prices, dp);
            int notSell = 0 + f(idx+1, 0, prices, dp);
            return dp[idx][buy] = max(sell, notSell);
        }
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // Rec + memo
        // vector<vector<int>> dp(n, vector<int>(2,-1));
        // return f(0,1,prices, dp);
        
        // Tabulation
//         vector<vector<int>> dp(n+2, vector<int>(2,0));
        
//         for(int idx=n-1; idx>=0; idx--) {
//             for(int buy=0; buy<=1; buy++) { 
//                 if(buy == 1) {
//                     int buyy = -prices[idx] + dp[idx+1][0];
//                     int notBuy = 0 + dp[idx+1][1];
//                     dp[idx][buy] = max(buyy, notBuy);
//                 } 
//                 else {
//                     int sell = prices[idx] + dp[idx+2][1];
//                     int notSell = 0 + dp[idx+1][0];
//                     dp[idx][buy] = max(sell, notSell);
//                 }
//             }
//         }
        
//         return dp[0][1];
        
        // you can remove the buy loop and execute both buy=0, buy=1 at once
        vector<vector<int>> dp(n+2, vector<int>(2,0));
        
        for(int idx=n-1; idx>=0; idx--) {
            int buyy = -prices[idx] + dp[idx+1][0];
            int notBuy = 0 + dp[idx+1][1];
            dp[idx][1] = max(buyy, notBuy);


            int sell = prices[idx] + dp[idx+2][1];
            int notSell = 0 + dp[idx+1][0];
            dp[idx][0] = max(sell, notSell);
        }
        
        return dp[0][1];

    }
};
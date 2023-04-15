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
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(0,1,prices, dp);
    }
};
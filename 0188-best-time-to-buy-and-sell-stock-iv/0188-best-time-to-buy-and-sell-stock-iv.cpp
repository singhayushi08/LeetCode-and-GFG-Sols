class Solution {
    int f(int idx, int buy, int k, vector<int>& prices, vector<vector<vector<int>>> &dp) {
        if(idx == prices.size() || k==0) return 0;
        
        if(dp[idx][buy][k] != -1) return dp[idx][buy][k];
        
        int profit = 0;
        if(buy == 1) {
            profit = max(-prices[idx]+f(idx+1, 0, k, prices,dp), 0+f(idx+1, 1, k, prices,dp));
        }
        else {
            profit = max(prices[idx]+f(idx+1, 1, k-1, prices,dp), 0+f(idx+1, 0, k, prices,dp));
        }
        
        return dp[idx][buy][k] = profit;
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0, 1, k, prices,dp);
    }
};
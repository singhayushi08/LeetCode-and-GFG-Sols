class Solution {
    int f(int idx, int buy, int k, vector<int>& prices, vector<vector<vector<int>>> &dp) { //buy = 1 means you can buy the stock, buy = 0 means its time to sell
        if(idx == prices.size() || k==0) return 0;
        
        if(dp[idx][buy][k] != -1) return dp[idx][buy][k];
        
        int profit = 0;
        if(buy == 1) { //if you can buy, either you buy or you don't
            profit = max(-prices[idx]+f(idx+1, 0, k, prices,dp), 0+f(idx+1, 1, k, prices,dp));
        }
        else { //else you have to sell, either you sell or you don't
            profit = max(prices[idx]+f(idx+1, 1, k-1, prices,dp), 0+f(idx+1, 0, k, prices,dp));
        }
        
        return dp[idx][buy][k] = profit;
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        // Memo
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return f(0, 1, k, prices,dp); 
        
        // Tabulation
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(k+1,0)));
        
//         for(int idx=n-1; idx>=0; idx--) {
//             for(int buy=0; buy<=1; buy++) {
//                 for(int cap=k; cap>0; cap--) {
//                     int profit = 0;
//                     if(buy == 1) { 
//                         profit = max(-prices[idx]+ dp[idx+1][0][cap], 0 + dp[idx+1][1][cap]);
//                     }
//                     else { 
//                         profit = max(prices[idx]+ dp[idx+1][1][cap-1], 0 + dp[idx+1][0][cap]);
//                     }

//                     dp[idx][buy][cap] = profit;
//                 }
//             }
//         }
        
//         return dp[0][1][k];
        
        // Space Optimised
        vector<vector<int>> next(2,vector<int>(k+1,0));
         vector<vector<int>> curr(2,vector<int>(k+1,0));
        
        for(int idx=n-1; idx>=0; idx--) {
            for(int buy=0; buy<=1; buy++) {
                for(int cap=k; cap>0; cap--) {
                    int profit = 0;
                    if(buy == 1) { 
                        profit = max(-prices[idx]+ next[0][cap], 0 + next[1][cap]);
                    }
                    else { 
                        profit = max(prices[idx]+ next[1][cap-1], 0 + next[0][cap]);
                    }

                    curr[buy][cap] = profit;
                }
            }
            next = curr;
        }
        
        return next[1][k];

    }
};
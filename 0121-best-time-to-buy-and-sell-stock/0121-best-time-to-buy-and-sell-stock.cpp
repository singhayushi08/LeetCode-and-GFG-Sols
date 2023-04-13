class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Brute force, TC: O(n^2), SC: O(1)
        // int maxi = 0;
        // int n = prices.size();
        // for(int i=0; i<n; i++) {
        //     for(int j=i+1; j<n; j++) {
        //         maxi = max(prices[j] - prices[i], maxi);
        //     }
        // }
        // return maxi;
        
        // Optimal using DP, TC: O(n), SC: O(1)
        int mini = prices[0], maxProfit = 0;
        for(int i=1; i<prices.size(); i++) {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
        
        
    }
};
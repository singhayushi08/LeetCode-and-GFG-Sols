class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) { // Variation of LIS
        sort(pairs.begin(), pairs.end());
        
        int n = pairs.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i=0; i<n; i++) {
            for(int prev=0; prev<i; prev++) {
                if(pairs[i][0] > pairs[prev][1] && dp[i] < 1 + dp[prev]) { 
                    dp[i] = 1 + dp[prev];   
                }
            }
            maxi = max(maxi, dp[i]);
        }
        
        return maxi;
    }
};
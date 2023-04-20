class Solution {
    int f(int idx, int prev, vector<vector<int>>& pairs) {
        if(idx == pairs.size()) return 0;
        int notPick = 0 + f(idx+1, prev, pairs);
        int pick = INT_MIN;
        if(prev == -1 || pairs[idx][0] > pairs[prev][1]) {
            pick = 1 + f(idx+1, idx, pairs);
        }
        return max(pick, notPick);
    }
    
    int memo(int idx, int prev, vector<vector<int>>& pairs, vector<vector<int>> &dp) {
        if(idx == pairs.size()) return 0;
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        
        int notPick = 0 + memo(idx+1, prev, pairs, dp);
        int pick = INT_MIN;
        if(prev == -1 || pairs[idx][0] > pairs[prev][1]) {
            pick = 1 + memo(idx+1, idx, pairs, dp);
        }
        return  dp[idx][prev+1] = max(pick, notPick);
    }
    
public:
    int findLongestChain(vector<vector<int>>& pairs) { // Variation of LIS
        // BEST: using DP, TC: O(n^2), SC: O(n)
//         sort(pairs.begin(), pairs.end());
        
//         int n = pairs.size();
//         vector<int> dp(n, 1);
//         int maxi = 1;
//         for(int i=0; i<n; i++) {
//             for(int prev=0; prev<i; prev++) {
//                 if(pairs[i][0] > pairs[prev][1] && dp[i] < 1 + dp[prev]) { 
//                     dp[i] = 1 + dp[prev];   
//                 }
//             }
//             maxi = max(maxi, dp[i]);
//         }
        
//         return maxi;
        
        // Pure LIS Recursion
        // sort(pairs.begin(), pairs.end());
        // return f(0, -1, pairs);
        
        // Memoization, TC: O(n^2), SC: O(n^2)
        // int n = pairs.size();
        // sort(pairs.begin(), pairs.end());
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return memo(0, -1, pairs, dp);
        
        // Tabulation, TC: O(n^2), SC: O(n^2)
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int idx=n-1; idx>=0; idx--) {
            for(int prev=idx; prev>=-1; prev--) {
                int notPick = 0 + dp[idx+1][prev+1];
                int pick = INT_MIN;
                if(prev == -1 || pairs[idx][0] > pairs[prev][1]) {
                    pick = 1 + dp[idx+1][idx+1];
                }
                dp[idx][prev+1] = max(pick, notPick);
            }
        }
        
        return dp[0][-1+1];
        
    }
};
class Solution {
    int f(int idx, int prev_idx, vector<vector<int>>& envelopes) {
        if(idx == envelopes.size()) return 0;
        
        int notPick = 0 + f(idx+1, prev_idx, envelopes);
        int pick = INT_MIN;
        if(prev_idx == -1 || (envelopes[idx][0] > envelopes[prev_idx][0] && envelopes[idx][1] > envelopes[prev_idx][1])) {
            pick = 1 + f(idx+1, idx, envelopes);
        } 
        
        return max(pick, notPick);
    }
    
    int memo(int idx, int prev_idx, vector<vector<int>>& envelopes, vector<vector<int>>& dp) {
        if(idx == envelopes.size()) return 0;
        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1];
        
        int notPick = 0 + memo(idx+1, prev_idx, envelopes, dp);
        int pick = INT_MIN;
        if(prev_idx == -1 || (envelopes[idx][0] > envelopes[prev_idx][0] && envelopes[idx][1] > envelopes[prev_idx][1])) {
            pick = 1 + memo(idx+1, idx, envelopes, dp);
        } 
        
        return dp[idx][prev_idx+1] = max(pick, notPick);
    }
    
    static bool comp(vector<int> &v1, vector<int> &v2) {
        // sort in increasing order in terms of width
        if(v1[0] < v2[0]) return true;
        if(v1[0] > v2[0]) return false;
        // if they are same, sort in decreasing order in terms of height
        if(v1[1] > v2[1]) return true;
        else return false;
    }
    
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) { // Variation of LIS
        // TC: O(n^2), SC: O(n) gives tle
//         sort(envelopes.begin(), envelopes.end());
//         int n = envelopes.size();
//         vector<int> dp(n, 1);
//         int maxi = 1;
        
//         for(int i=0; i<n; i++) {
//             for(int prev=0; prev<i; prev++) {
//                 if(envelopes[i][0] > envelopes[prev][0] && envelopes[i][1] > envelopes[prev][1] && dp[i] < 1 + dp[prev]) {
//                     dp[i] = 1 + dp[prev];
//                 }
//             }
//             maxi = max(dp[i], maxi);
//         }
        
//         return maxi;
        
        // Recursion, TC: expo, SC: O(n) gives tle
        // sort(envelopes.begin(), envelopes.end());
        // return f(0, -1, envelopes);
        
        // Memoization, TC: O(n^2), SC: O(n^2 + n) gives tle
        // int n = envelopes.size();
        // sort(envelopes.begin(), envelopes.end());
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return memo(0, -1, envelopes, dp);
        
        // Tabulation, TC: O(n^2), SC: O(n^2) gives tle
//         int n = envelopes.size();
//         sort(envelopes.begin(), envelopes.end());
//         vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
//         for(int idx=n-1; idx>=0; idx--) {
//             for(int prev_idx=idx; prev_idx>=-1; prev_idx--) {
//                 int notPick = 0 + dp[idx+1][prev_idx+1];
//                 int pick = INT_MIN;
//                 if(prev_idx == -1 || (envelopes[idx][0] > envelopes[prev_idx][0] && envelopes[idx][1] > envelopes[prev_idx][1])) {
//                     pick = 1 + dp[idx+1][idx+1];
//                 } 

//                 dp[idx][prev_idx+1] = max(pick, notPick);
//             }
//         }
        
//         return dp[0][-1+1];
        
        // Space Optimisation, TC: O(n^2), SC: O(2n) gives tle
//         int n = envelopes.size();
//         sort(envelopes.begin(), envelopes.end());
//         vector<int> next(n+1, 0), curr(n+1, 0);
        
//         for(int idx=n-1; idx>=0; idx--) {
//             for(int prev_idx=idx; prev_idx>=-1; prev_idx--) {
//                 int notPick = 0 + next[prev_idx+1];
//                 int pick = INT_MIN;
//                 if(prev_idx == -1 || (envelopes[idx][0] > envelopes[prev_idx][0] && envelopes[idx][1] > envelopes[prev_idx][1])) {
//                     pick = 1 + next[idx+1];
//                 } 

//                 curr[prev_idx+1] = max(pick, notPick);
//             }
//             next = curr;
//         }
        
//         return next[-1+1];
        
        
        // DP with Binary Search, TC: O(nlogn), SC: O(n) 
        int n = envelopes.size();
        // sort in terms of increasing width, now dont worry about width
        // if same width, then sort in decreasing order of height and call LIS on height column only coz width is already handled
        
        // sorting logic => https://leetcode.com/problems/russian-doll-envelopes/discuss/2071477/Best-Explanation-with-Pictures
        sort(envelopes.begin(), envelopes.end(), comp); 
        
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        
        for(int i=1; i<n; i++) {
            if(envelopes[i][1] > temp.back()) {
                temp.push_back(envelopes[i][1]);
            } 
            else {
                int idx = lower_bound(temp.begin(), temp.end(), envelopes[i][1]) - temp.begin();
                temp[idx] = envelopes[i][1];
            }
        }
        
        return temp.size();
        
        
    }
};
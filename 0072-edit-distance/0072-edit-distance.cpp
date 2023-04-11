class Solution {
    int f(int i, int j, string s1, string s2) {
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        
        if(s1[i] == s2[j]) {
            return 0 + f(i-1, j-1, s1, s2);
        }
        
        int a = 1 + f(i, j-1, s1, s2); // insert
        int b = 1 + f(i-1, j, s1, s2); // delete
        int c = 1 + f(i-1, j-1, s1, s2); // replace
        
        return min(a, min(b,c));
    }
    
    int memo(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i == 0) return j;
        if(j == 0) return i;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i-1] == s2[j-1]) {
            return dp[i][j] = 0 + memo(i-1, j-1, s1, s2, dp);
        }
        
        
        int a = 1 + memo(i, j-1, s1, s2, dp); // insert
        int b = 1 + memo(i-1, j, s1, s2, dp); // delete
        int c = 1 + memo(i-1, j-1, s1, s2, dp); // replace
        
        return dp[i][j] = min(a, min(b,c));
    }
    
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        // Recursion, TC: expontential, SC: O(n+m)
        // return f(n, m, word1, word2);
        
        // Memoization, TC: O(n*m), SC: O(n*m + n+m) for 2d array and rec stack space
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return memo(n, m, word1, word2, dp);
        
        // Tabulation, TC: O(n*m), SC: O(n*m)
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
//         for(int j=0; j<=m; j++) dp[0][j] = j;
//         for(int i=0; i<=n; i++) dp[i][0] = i;
        
//         for(int i=1; i<=n; i++) {
//             for(int j=1; j<=m; j++) {
//                 if(word1[i-1] == word2[j-1]) {
//                     dp[i][j] = 0 + dp[i-1][j-1];
//                 }
//                 else {
//                     int a = 1 + dp[i][j-1]; // insert
//                     int b = 1 + dp[i-1][j]; // delete
//                     int c = 1 + dp[i-1][j-1]; // replace

//                     dp[i][j] = min(a, min(b,c));    
//                 }   
//             }
//         }
        
//         return dp[n][m];
        
        // Space Optimised, TC: O(n*m), SC: O(m)
        vector<int> prev(m+1, 0), curr(m+1, 0);
        for(int j=0; j<=m; j++) prev[j] = j;
         
        for(int i=1; i<=n; i++) {
            curr[0] = i;
            for(int j=1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    curr[j] = 0 + prev[j-1];
                }
                else {
                    int a = 1 + curr[j-1]; // insert
                    int b = 1 + prev[j]; // delete
                    int c = 1 + prev[j-1]; // replace

                    curr[j] = min(a, min(b,c));    
                }   
            }
            prev = curr;
        }
        
        return prev[m];
        
        

        
        
    }
};
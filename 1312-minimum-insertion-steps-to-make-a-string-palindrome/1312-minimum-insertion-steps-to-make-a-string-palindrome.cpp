class Solution {
    
    int lcs(string s1, string s2, int n, int m) {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int j=0; j<=m; j++) dp[0][j] = 0;
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
        
    }
    int longestPalindromicSubsequence(string s) {  // just find lcs of s and rev(s)
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t, s.size(), t.size());
    }
    
public:
    int minInsertions(string s) {
        // TC: O(n*m), SC: O(n*m)
        return s.size() - longestPalindromicSubsequence(s);
    }
};
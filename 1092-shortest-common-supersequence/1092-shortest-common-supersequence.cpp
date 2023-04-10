class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // keep the Longest common subsequence intact in both the strings
        // then length of shortest common supersequence => n + m - lcs (coz lcs is common in both of them)
        // print SCS by backtracking LCS
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // for(int j=0; j<=m; j++) dp[0][j] = 0;
        // for(int i=0; i<=n; i++) dp[i][0] = 0;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int i=n, j=m;
        string ans = "";
        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                ans += str1[i-1]; // or use ans.push_back(str1[i-1])
                i--;
                j--;
            } 
            else if(dp[i-1][j] > dp[i][j-1]) { // go up
                ans += str1[i-1];
                i--;
            } 
            else { // go left
                ans += str2[j-1]; 
                j--;
            }
        }
        
        // add if characters remaining in either of the str
        while(i > 0 ) {
            ans += str1[i-1];
            i--;
        }
        while(j > 0) {
            ans += str2[j-1];
            j--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
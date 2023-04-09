class Solution {
  
public:
    string longestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int j=0; j<=m; j++) dp[0][j] = 0;
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        
        int len = 0, x = 0, y = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(dp[i][j] > len && i-dp[i][j] == n-j) {
                        len = dp[i][j];
                        x = i;
                        y = j;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        // for(int i=0; i<=n; i++) {
        //     for(int j=0; j<=m; j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        string res = "";
        while(dp[x][y] != 0) {
            res.push_back(s[x-1]);
            x--;
            y--;
        }
        reverse(res.begin(), res.end());
        
        return res;
        
        
    }
};
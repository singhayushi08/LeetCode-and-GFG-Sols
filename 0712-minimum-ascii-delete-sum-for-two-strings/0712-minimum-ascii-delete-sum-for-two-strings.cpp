class Solution {
    int asciisum(string s, int low, int high) {
        int sum = 0;
        for(int i=low; i<=high; i++) {
            sum += s[i];
        }
        return sum;
    }
     
//     int f(int i, int j, string &s1, string &s2) {
//         if(i == -1 && j == -1) return 0;
//         if(i == -1 && j != -1) {
//             return asciisum(s2, 0, j);
//         }
//         if(j == -1 && i != -1) {
//             return asciisum(s1, 0, i);
//         }
        
//         if(s1[i] == s2[j]) {
//             return 0 + f(i-1, j-1, s1, s2);
//         }
//         else {
//             int option1 = s1[i] + f(i-1, j, s1, s2);
//             int option2 = s2[j] + f(i, j-1, s1, s2);
//             return min(option1, option2);
//         }
//     }
    
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) return 0;
        if(i == 0 && j != 0) {
            return asciisum(s2, 0, j-1);
        }
        if(j == 0 && i != 0) {
            return asciisum(s1, 0, i-1);
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i-1] == s2[j-1]) {
            return dp[i][j] = 0 + f(i-1, j-1, s1, s2, dp);
        }
        else {
            int option1 = s1[i-1] + f(i-1, j, s1, s2, dp);
            int option2 = s2[j-1] + f(i, j-1, s1, s2, dp);
            return dp[i][j] = min(option1, option2);
        }
    }
    
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // return f(n-1, m-1, s1, s2);
        
        // Memoization, converted into 1 based indexing
//         vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
//         return f(n, m, s1, s2, dp);
        
        // Tabulation
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][0] = 0;
        for(int j=1; j<=m; j++) {
            dp[0][j] = s2[j-1] + dp[0][j-1];
        }
        for(int i=1; i<=n; i++) {
            dp[i][0] = s1[i-1] + dp[i-1][0];
        }
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 0 + dp[i-1][j-1];
                }
                else {
                    int option1 = s1[i-1] + dp[i-1][j];
                    int option2 = s2[j-1] + dp[i][j-1];
                    dp[i][j] = min(option1, option2);
                }
            }
        }
        
        return dp[n][m];
 
    }
};
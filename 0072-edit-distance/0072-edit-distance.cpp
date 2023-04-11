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
    
    int memo(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) {
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
        
        // Recursion
        // return f(n-1, m-1, word1, word2);
        
        // Memoization
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return memo(n-1, m-1, word1, word2, dp);
    }
};
class Solution {
    bool f(int i, int j, string &s, string &p) {
        if(i < 0 && j < 0) return true;
        if(j < 0 && i >= 0) return false;
        if(i < 0 && j >= 0) {
            for(int k=0; k<=i; k++) {
                if(p[k] != '*') return false;
            }
            return true;
        }
        
        if(s[i] == p[j] || p[j] == '?') {
            return f(i-1, j-1, s, p);
        } 
        if(p[j] == '*') {
            return f(i, j-1, s, p) || f(i-1, j, s, p);
        }
        
        return false;
    }
    
    bool memo(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if(i < 0 && j < 0) return true;
        if(j < 0 && i >= 0) return false;
        if(i < 0 && j >= 0) {
            for(int k=0; k<=j; k++) {
                if(p[k] != '*') return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = memo(i-1, j-1, s, p, dp);
        } 
        if(p[j] == '*') {
            return dp[i][j] = memo(i, j-1, s, p, dp) || memo(i-1, j, s, p, dp);
        }
        
        return dp[i][j] = false;
    }
    
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        // Recursion
        // return f(n-1, m-1, s, p);
        
        // Memoization
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return memo(n-1, m-1, s, p, dp);
    }
};
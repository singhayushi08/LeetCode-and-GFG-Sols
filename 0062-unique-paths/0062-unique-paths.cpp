class Solution {
    int helper(int i, int j, int m, int n) { // from 0,0 to m-1, n-1
        if(i == m-1 && j == n-1) return 1; // base case
        
        int down = 0, right = 0;
        if(i+1 < m) {
            down = helper(i+1, j, m, n);
        }
        if(j+1 < n) {
            right = helper(i, j+1, m, n);
        }
        
        return down + right;
    }
    
    int f(int i, int j) { // from m-1, n-1 to 0,0
        if(i == 0 && j == 0) return 1; 
        
        int up = 0, left = 0; // Here down will become up and right will become left
        if(i-1 >= 0) {
            up = f(i-1, j);
        }
        if(j-1 >= 0) {
            left = f(i, j-1);
        }
        
        return up + left;
    }
    
    int memo(int i, int j, vector<vector<int>> &dp) { // from m-1, n-1 to 0,0
        if(i == 0 && j == 0) return 1; 
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = 0, left = 0; // Here down will become up and right will become left
        if(i-1 >= 0) {
            up = memo(i-1, j, dp);
        }
        if(j-1 >= 0) {
            left = memo(i, j-1, dp);
        }
        
        return dp[i][j] = up + left;
    }
    
    
    
public:
    int uniquePaths(int m, int n) {
        // Recursion, TC: O(2^(m*n)), SC: O(path length: m-1 + n-1) which is the depth of rec tree i.e. rec stack space
        // return helper(0, 0, m, n);
        
        // OR recursion, TC: O(2^(m*n)), SC: O(path length: m-1 + n-1) which is the depth of rec tree
        // return f(m-1, n-1);
        
        // Memoization, TC: O(m*n), SC: O(m*n for 2d array + m-1+n-1 for rec stack space)
        // vector<vector<int>> dp(m, vector<int>(n,-1));
        // return memo(m-1, n-1, dp);
        
        // Tabulation, TC: O(m*n), SC: O(m*n) only for 2d array
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i == 0 && j == 0) dp[i][j] = 1;
                else {
                    int left = 0, up = 0;
                    if(i-1 >= 0) up = dp[i-1][j];
                    if(j-1 >= 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        
        return dp[m-1][n-1];
        
        
        
        
    }
};
class Solution {
    int f(int i, int j, vector<vector<int>>& grid) {
        if(i == 0 && j == 0) {
            return grid[0][0];
        }
        
        int up = INT_MAX, left = INT_MAX;
        if(i-1 >= 0) up = f(i-1, j, grid);
        if(j-1 >= 0) left = f(i, j-1, grid);
        
        return grid[i][j] + min(up, left);
    }
    
    int memo(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) {
            return grid[0][0];
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = INT_MAX, left = INT_MAX;
        if(i-1 >= 0) up = memo(i-1, j, grid, dp);
        if(j-1 >= 0) left = memo(i, j-1, grid, dp);
        
         return dp[i][j] = grid[i][j] + min(up, left);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Recursion, TC: O(2^(m*n)), SC: O(m-1 + n-1) path length i.e. rec stack space
        // return f(m-1, n-1, grid);
        
        // Memoization, TC: O(m*n), SC: O(m*n + m-1+n-1) for 2d array and rec stack space  
        // vector<vector<int>> dp(m, vector<int>(n,-1));
        // return memo(m-1, n-1, grid, dp);
        
        // Tabulation, TC: O(m*n), SC: O(m*n)
//         vector<vector<int>> dp(m, vector<int>(n,0));
//         dp[0][0] = grid[0][0];
        
//         for(int i=0; i<m; i++) {
//             for(int j=0; j<n; j++) {
//                 if(i == 0 && j == 0) {
//                     dp[i][j] = grid[0][0];
//                 } 
//                 else {
//                     int up = INT_MAX, left = INT_MAX;
//                     if(i-1 >= 0) up = dp[i-1][j];
//                     if(j-1 >= 0) left = dp[i][j-1];
                    
//                     dp[i][j] = grid[i][j] + min(up, left);
//                 }
//             } 
//         }
        
//         return dp[m-1][n-1];
        
        // Space Optimisation, TC: O(m*n), SC: O(n)
        vector<int> prev(n,0);
        prev[0] = grid[0][0];
        
        for(int i=0; i<m; i++) {
            vector<int> curr(n,0);
            for(int j=0; j<n; j++) {
                if(i == 0 && j == 0) {
                    curr[j] = grid[0][0];
                } 
                else {
                    int up = INT_MAX, left = INT_MAX;
                    if(i-1 >= 0) up = prev[j];
                    if(j-1 >= 0) left = curr[j-1];
                    
                    curr[j] = grid[i][j] + min(up, left);
                }
            } 
            prev = curr;
        }
        
        return prev[n-1];
        
    }
};
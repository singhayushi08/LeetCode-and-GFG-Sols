class Solution {
    int f(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid) {
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;
        if(i == n-1) {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        int maxi = -1e8;
        // traverse all paths of both robots simultaneously
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                int val = 0;
                if(j1 == j2) val = grid[i][j1];
                else val = grid[i][j1] + grid[i][j2];
                
                val += f(i+1, dj1+j1, dj2+j2, n, m, grid);
                maxi = max(val, maxi);
            }
        }
        
        return maxi;
    }
    
    int memo(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;
        if(i == n-1) {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = -1e8;
        // traverse all paths of both robots simultaneously
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                int val = 0;
                if(j1 == j2) val = grid[i][j1];
                else val = grid[i][j1] + grid[i][j2];
                
                val += memo(i+1, dj1+j1, dj2+j2, n, m, grid, dp);
                maxi = max(val, maxi);
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
    
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Recursion, TC: O(3^n * 3^n) for each robot we have 3 moves at each cell, SC: O(n) for aux stack space
        // return f(0, 0, m-1, n, m, grid);
        
        // Memoization, TC: O(n*m*m), SC: O(n*m*m + n) for 3d dp and rec stack space
        // 3d dp as 3 values are changing => i, j1, j2
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return memo(0, 0, m-1, n, m, grid, dp);
        
    }
};
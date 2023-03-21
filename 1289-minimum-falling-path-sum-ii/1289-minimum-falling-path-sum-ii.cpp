class Solution {
    int f(int i, int last, int n, vector<vector<int>> &grid) { //going from f(n-1, j) to f(0,j)
        if(i == 0) { // base case
            int mini = INT_MAX;
            for(int j=0; j<n; j++) {
                if(j != last) {
                    mini = min(mini, grid[0][j]);
                }
            }
            return mini;
        }
        
        int mini = INT_MAX;
        for(int j=0; j<n; j++) {
            if(j != last) {
                int temp = grid[i][j] + f(i-1, j, n, grid);
                mini = min(mini, temp);
            }
        }
        return mini;
    }
    
    int memo(int i, int last, int n, vector<vector<int>> &grid, vector<vector<int>> &dp) { //f(n-1, j) to f(0,j)
        if(i == 0) { // base case
            int mini = INT_MAX;
            for(int j=0; j<n; j++) {
                if(j != last) {
                    mini = min(mini, grid[0][j]);
                }
            }
            return mini;
        }
        
        if(dp[i][last] != -1) return dp[i][last];
        
        int mini = INT_MAX;
        for(int j=0; j<n; j++) {
            if(j != last) {
                int temp = grid[i][j] + memo(i-1, j, n, grid, dp);
                mini = min(mini, temp);
            }
        }
        return dp[i][last] = mini;
    }
    
    int f(int i, int j, vector<vector<int>>& grid) {
        if(i == 0) return grid[i][j];
        
        int mini = INT_MAX;
        for(int k=0; k<grid[0].size(); k++) {
            if(k != j) {
                int temp = grid[i][j] + f(i-1, k, grid);
                mini = min(mini, temp);
            }
        }
        
        return mini;
    }
    
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if(i == 0) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int k=0; k<grid[0].size(); k++) {
            if(k != j) {
                int temp = grid[i][j] + solve(i-1, k, grid, dp);
                mini = min(mini, temp);
            }
        }
        
        return dp[i][j] = mini;
    }
    
    
    
public:
    int minFallingPathSum(vector<vector<int>>& grid) { 
        // SIMILAR TO NINJA TRAINING
        // int n = grid.size();
        
        // Recursion, TC: O(2^n), SC: O(n) for rec tree depth
        // return f(n-1, n, n, grid); //passing nth index as last chosen element, means none taken yet
        
        // Memoization, TC: O(n*n), SC: O(n*n + n) for 2d array and rec stack space
        // max value of i=>n-1 and last=>n
        // vector<vector<int>> dp(n, vector<int>(n+1,-1));
        // return memo(n-1, n, n, grid, dp);
        
        // BETTER APPROACH: VARIABLE STARTING AND ENDING POINT METHOD
        
        // OR Recursion
        // int n = grid.size();
        // int m = grid[0].size();
        // int ans = INT_MAX;
        
        // make every element of last row as starting point and ending point will be any element on 0th row
        // for(int j=0; j<m; j++) { 
        //     ans = min(ans, f(n-1, j, grid));
        // }
        // return ans;
        
        // Memoization, TC: O(n*m), SC: O(n*m + n) for 2d array and rec stack space
        int n = grid.size();
        int m = grid[0].size(); //just in case n and m were different
        vector<vector<int>> dp(n, vector<int>(m,-1));
        int ans = INT_MAX;
        
        for(int j=0; j<m; j++) {
            ans = min(ans, solve(n-1, j, grid, dp));
        }
        return ans;
        
        // Tabulation
        
        
        
        
        
        
        
    }
};
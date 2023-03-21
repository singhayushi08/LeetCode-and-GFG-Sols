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
        
        // Memoization, TC: O(n*m*m), SC: O(n*m + n) for 2d array and rec stack space
//         int n = grid.size();
//         int m = grid[0].size(); //just in case n and m were different
//         vector<vector<int>> dp(n, vector<int>(m,-1));
//         int ans = INT_MAX;
        
//         for(int j=0; j<m; j++) {
//             ans = min(ans, solve(n-1, j, grid, dp));
//         }
//         return ans;
        
        // Tabulation, TC: O(n*m*m), SC: O(n*m)
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m,0));
        
//         // fill 1st row
//         for(int j=0; j<m; j++) {
//             dp[0][j] = grid[0][j];
//         }
        
//         for(int i=1; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 int mini = INT_MAX;
//                 for(int k=0; k<m; k++) {
//                     if(k != j) {
//                         int temp = grid[i][j] + dp[i-1][k];
//                         mini = min(mini, temp);
//                     }
//                 }
//                 dp[i][j] = mini;
//             }
//         }
        
//         int ans = dp[n-1][0];
//         for(int j=1; j<m; j++) {
//             ans = min(ans, dp[n-1][j]);
//         }
//         return ans;
        
        // Space Optimisation, TC: O(n*m*m), SC: O(n)
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m,0);
        
        // fill 1st row
        for(int j=0; j<m; j++) {
            prev[j] = grid[0][j];
        }
        
        for(int i=1; i<n; i++) {
            vector<int> curr(m,0);
            for(int j=0; j<m; j++) {
                int mini = INT_MAX;
                for(int k=0; k<m; k++) {
                    if(k != j) {
                        int temp = grid[i][j] + prev[k];
                        mini = min(mini, temp);
                    }
                }
                curr[j] = mini;
            }
            prev = curr;
        }
        
        int ans = prev[0];
        for(int j=1; j<m; j++) {
            ans = min(ans, prev[j]);
        }
        return ans;
            
        
        
        
        
        
        
    }
};
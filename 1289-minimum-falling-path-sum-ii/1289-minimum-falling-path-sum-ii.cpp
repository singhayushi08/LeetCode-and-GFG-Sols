class Solution {
    int f(int i, int last, int n, vector<vector<int>> &grid) { //f(n-1, j) to f(0,j)
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
    
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Recursion, TC: O(2^n), SC: O(n) for rec tree depth
        // return f(n-1, n, n, grid); //passing nth index as last chosen element, means none taken yet
        
        // Memoization, TC: O(n*n), SC: O(n*n + n) for 2d array and rec stack space
        // max value of i=>n-1 and last=>n
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return memo(n-1, n, n, grid, dp); 
    }
};
class Solution {
    int f(int i, int j, vector<vector<int>>& obstacleGrid) {
        if(i == 0 && j == 0) return 1; // base case
        
        int up = 0, left = 0; 
        if(i-1 >= 0 && obstacleGrid[i-1][j] == 0) {
            up = f(i-1, j, obstacleGrid);
        }
        if(j-1 >= 0 && obstacleGrid[i][j-1] == 0) {
            left = f(i, j-1, obstacleGrid);
        }
        
        return up + left;
    }
    
    int memo(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return 1; // base case
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = 0, left = 0; 
        if(i-1 >= 0 && obstacleGrid[i-1][j] == 0) {
            up = memo(i-1, j, obstacleGrid, dp);
        }
        if(j-1 >= 0 && obstacleGrid[i][j-1] == 0) {
            left = memo(i, j-1, obstacleGrid, dp);
        }
        
        return dp[i][j] = up + left;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Recursion
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // if(obstacleGrid[m-1][n-1] == 0) return f(m-1, n-1, obstacleGrid);
        // return 0;
        
        // Memoization
        vector<vector<int>> dp(m, vector<int>(n,-1));
        if(obstacleGrid[m-1][n-1] == 0) return memo(m-1, n-1, obstacleGrid, dp);
        return 0;        
    }
};
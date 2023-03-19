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
        // Recursion, TC: O(2^(m*n)), SC: O(m-1 + n-1 => path length)
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // if(obstacleGrid[m-1][n-1] == 0) return f(m-1, n-1, obstacleGrid);
        // return 0;
        
        // Memoization, TC: O(m*n), SC: O(m*n for 2d array + m-1+n-1 for rec stack space)
        // vector<vector<int>> dp(m, vector<int>(n,-1));
        // if(obstacleGrid[m-1][n-1] == 0) return memo(m-1, n-1, obstacleGrid, dp);
        // return 0;        
        
        // Tabulation, TC: O(m*n), SC: O(m*n) only for 2d array
//         if(obstacleGrid[m-1][n-1] == 1) return 0;
//         vector<vector<int>> dp(m, vector<int>(n));
//         dp[0][0] = 1;
        
//         for(int i=0; i<m; i++) {
//             for(int j=0; j<n; j++) {
//                 if(i == 0 && j == 0) {
//                     dp[i][j] = 1;
//                 }
//                 else {
//                     int up = 0, left = 0;
//                     if(i-1 >= 0 && obstacleGrid[i-1][j] == 0) {
//                         up = dp[i-1][j];
//                     }
//                     if(j-1 >= 0 && obstacleGrid[i][j-1] == 0) {
//                         left = dp[i][j-1];
//                     }
                    
//                     dp[i][j] = up + left;
//                 }
//             }
//         }
        
//         return dp[m-1][n-1];
        
        // Space Optimisation, TC: O(m*n), SC: O(n)
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        vector<int> prev(n,0);
        prev[0] = 1;
        
        for(int i=0; i<m; i++) {
            vector<int> curr(n,0);
            for(int j=0; j<n; j++) {
                if(i == 0 && j == 0) {
                    curr[j] = 1;
                }
                else {
                    int up = 0, left = 0;
                    if(i-1 >= 0 && obstacleGrid[i-1][j] == 0) {
                        up = prev[j];
                    }
                    if(j-1 >= 0 && obstacleGrid[i][j-1] == 0) {
                        left = curr[j-1];
                    }
                    
                    curr[j] = up + left;
                }
            }
            prev = curr; // curr will become prev
        }
        
        return prev[n-1];
        
        
    }
};
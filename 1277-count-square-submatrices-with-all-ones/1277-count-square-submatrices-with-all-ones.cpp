class Solution {
    int f(vector<vector<int>>& matrix, int m, int n, int i, int j) {
        if(i<0 || j<0|| i>=m || j>=n || matrix[i][j] == 0) {
            return 0;
        }
        
        int right = f(matrix, m, n, i, j+1);
        int down = f(matrix, m, n, i+1, j);
        int diag = f(matrix, m, n, i+1, j+1); // down right diagonal
        
        return 1 + min(right, min(down, diag));
    }
    
    int memo(vector<vector<int>>& matrix, int m, int n, int i, int j, vector<vector<int>>& dp) {
        if(i<0 || j<0|| i>=m || j>=n || matrix[i][j] == 0) {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = memo(matrix, m, n, i, j+1, dp);
        int down = memo(matrix, m, n, i+1, j, dp);
        int diag = memo(matrix, m, n, i+1, j+1, dp); // down right diagonal
        
        return dp[i][j] = 1 + min(right, min(down, diag));
    }
    
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Recursion, TC: exponential
//         int m =  matrix.size();
//         int n = matrix[0].size();
        
//         int cnt = 0;
//         for(int i=0; i<m; i++) {
//             for(int j=0; j<n; j++) {
//                 cnt += f(matrix, m, n, i, j);
//             }
//         } 
//         return cnt;
        
        // Memoization, TC: O(m*n), SC: O(m*n + m) for 2d vector and rec stack space
        int m =  matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int cnt = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 1) {
                    cnt += memo(matrix, m, n, i, j, dp);
                }
                // else you cannot form a 1s square
            }
        } 
        return cnt;
        
        
        // Tabulation, TC: O(m*n), SC: O(m*n)
//         int m = matrix.size();
//         int n = matrix[0].size();
        
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         // dp[i][j] signifies how many squares with all 1s having bottom right corner at matrix[i][j]
//         for(int j=0; j<n; j++) {
//             dp[0][j] = matrix[0][j];
//         }
//         for(int i=0; i<m; i++) {
//             dp[i][0] = matrix[i][0];
//         }
        
//         for(int i=1; i<m; i++) {
//             for(int j=1; j<n; j++) {
//                 if(matrix[i][j] == 1) {
//                     dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
//                 } else {
//                     dp[i][j] = 0;
//                 }
//             }
//         }
        
//         int sum = 0;
//         for(int i=0; i<m; i++) {
//             for(int j=0; j<n; j++) {
//                 sum += dp[i][j];
//             }
//         }
        
//         return sum;
    }
};
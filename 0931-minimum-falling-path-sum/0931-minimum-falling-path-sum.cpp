class Solution {
    int f(int i, int j, int n, vector<vector<int>>& matrix) { //from n-1,n-1 to 0th row
        if(i == 0) return matrix[0][j]; 
        
        int ld = INT_MAX, rd = INT_MAX;
        int up = matrix[i][j] + f(i-1, j, n, matrix); // row i will never go out of bound but j can
        
        if(j-1 >= 0) ld = matrix[i][j] + f(i-1, j-1, n, matrix); // left upper diagonal 
        if(j+1 < n) rd = matrix[i][j] + f(i-1, j+1, n, matrix); // right upper diagonal
        
        return min(up, min(ld, rd));
    }
    
    int memo(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) { //from n-1,n-1 to 0th row
        if(i == 0) return matrix[0][j]; 
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ld = INT_MAX, rd = INT_MAX;
        int up = matrix[i][j] + memo(i-1, j, n, matrix, dp); // row i will never go out of bound but j can
        
        if(j-1 >= 0) ld = matrix[i][j] + memo(i-1, j-1, n, matrix, dp); // left upper diagonal 
        if(j+1 < n) rd = matrix[i][j] + memo(i-1, j+1, n, matrix, dp); // right upper diagonal
        
        return dp[i][j] = min(up, min(ld, rd));
    }
    
    
   
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Recursion, TC: O(3^(n*n)), SC: O(n) 
        // int ans = INT_MAX;
        // for(int j=0; j<n; j++) {
        //     ans = min(ans, f(n-1, j, n, matrix));
        // }
        // return ans;
        
        // Memoization, TC: O(n*n), SC: O(n*n + n) for 2d array and rec stack space
        // vector<vector<int>> dp(n, vector<int>(n,-1));
        // int ans = INT_MAX;
        // for(int j=0; j<n; j++) {
        //     ans = min(ans, memo(n-1, j, n, matrix, dp));
        // }
        // return ans;
        
        // Tabulation, TC: O(n*n), SC: O(n*n) only for 2d array
        // Rec from  n-1,n-1 to oth row
        // Tabulation from 0th to n-1,n-1
        vector<vector<int>> dp(n, vector<int>(n,0));
        
        // fill first row
        for(int j=0; j<n; j++) {
            dp[0][j] = matrix[0][j];
        }
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                int up = matrix[i][j] + dp[i-1][j];
                int ld = INT_MAX, rd = INT_MAX;
                if(j-1 >= 0) ld = matrix[i][j] + dp[i-1][j-1];
                if(j+1 < n) rd = matrix[i][j] + dp[i-1][j+1];
                
                dp[i][j] = min(up, min(ld, rd));
            }
        }
        
        int mini = INT_MAX;
        for(int j=0; j<n; j++) {
            mini = min(dp[n-1][j], mini);
        }
        
        return mini;
        
    }
};
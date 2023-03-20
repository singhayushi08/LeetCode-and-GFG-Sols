class Solution {
    
    int f(int i, int j, int n, vector<vector<int>>& triangle) { //f(0,0) => min path sum from 0,0 to n-1,n-1
        if(i == n-1) { // base case
            return triangle[i][j];
        }    
        
        // we will never go out of bound coz j<=i always, so no condition check is required
        int down = triangle[i][j] + f(i+1, j, n, triangle); // down
        int diag = triangle[i][j] + f(i+1, j+1, n, triangle); // right down diagonal
        
        return min(down, diag);
    }
    
    int memo(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>> &dp) {
        if(i == n-1) {
            return triangle[i][j];
        }    
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + memo(i+1, j, n, triangle, dp); // down
        int diag = triangle[i][j] + memo(i+1, j+1, n, triangle, dp); // right down diagonal
        
        return dp[i][j] = min(down, diag);
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // Recursion, TC: O(2^n), SC: O(n)
        // return f(0, 0, n, triangle);
        
        // Memoization, TC: O(n*n), SC: O(n*n + n) for 2d array and rec stack space
        // vector<vector<int>> dp(n, vector<int>(n,-1));
        // return memo(0, 0, n, triangle, dp);
        
        // Tabulation, TC: O(n*n), SC: O(n*n) for 2d array only
        // we did rec from 0,0 to n-1, n-1
        // tabulation is exact opposite, so n-1,n-1 to 0,0
        
        vector<vector<int>> dp(n, vector<int>(n,0));
        
        // fill last (n-1)th row
        for(int j=0; j<n; j++) {
            dp[n-1][j] = triangle[n-1][j];
        }
        
        for(int i=n-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                int down = triangle[i][j] + dp[i+1][j]; // down
                int diag = triangle[i][j] + dp[i+1][j+1]; // right down diagonal
                
                dp[i][j] = min(down, diag);
            }
        }
        
        return dp[0][0];
    }
};
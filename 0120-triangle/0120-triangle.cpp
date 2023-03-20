class Solution {
    
    int f(int i, int j, int n, vector<vector<int>>& triangle) {
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
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return memo(0, 0, n, triangle, dp);
    }
};
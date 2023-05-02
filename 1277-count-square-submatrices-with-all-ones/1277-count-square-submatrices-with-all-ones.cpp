class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Tabulation, TC: O(m*n), SC: O(m*n)
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // dp[i][j] signifies how many squares with all 1s having bottom right corner at matrix[i][j]
        for(int j=0; j<n; j++) {
            dp[0][j] = matrix[0][j];
        }
        for(int i=0; i<m; i++) {
            dp[i][0] = matrix[i][0];
        }
        
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j] == 1) {
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        int sum = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                sum += dp[i][j];
            }
        }
        
        return sum;
    }
};
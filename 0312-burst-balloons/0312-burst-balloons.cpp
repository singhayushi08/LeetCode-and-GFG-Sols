class Solution {
    int f(int i, int j, vector<int>& nums) {
        if(i > j) return 0; // base case
        
        int maxi = INT_MIN;
        for(int k=i; k<=j; k++) {
            int coins = nums[i-1] * nums[k] * nums[j+1] + f(i, k-1, nums) + f(k+1, j, nums);
            maxi = max(coins, maxi);
        }
        
        return maxi;
    }
    
    int memo(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i > j) return 0; // base case
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxi = INT_MIN;
        for(int k=i; k<=j; k++) {
            int coins = nums[i-1] * nums[k] * nums[j+1] + memo(i, k-1, nums, dp) + memo(k+1, j, nums, dp);
            maxi = max(coins, maxi);
        }
        
        return dp[i][j] = maxi;
    }
    
public:
    int maxCoins(vector<int>& nums) { // Variation of MCM
        
        // Recursion
        // int n = nums.size();
        // nums.push_back(1);
        // nums.insert(nums.begin(), 1);
        // return f(1, n, nums);
        
        // Memoization, TC: O(N^3), SC: O(N^2 + N)
        // int n = nums.size();
        // nums.push_back(1);
        // nums.insert(nums.begin(), 1);
        // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        // return memo(1, n, nums, dp);
        
        // Tabulation, TC: O(N^3), SC: O(N^2)
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        for(int i=n; i>=1; i--) {
            for(int j=1; j<=n; j++) {
                if(i > j) continue;
                int maxi = INT_MIN;
                for(int k=i; k<=j; k++) {
                    int coins = nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(coins, maxi);
                }

                dp[i][j] = maxi;
            }
        }
        
        return dp[1][n];
        
        
    }
};
class Solution {
    int f(int i, int j, vector<int>& cuts) {
        if(i > j) return 0; // base case
        
        int mini = INT_MAX;
        for(int k=i; k<=j; k++) { // make cuts
            int cost = cuts[j+1] - cuts[i-1] + f(i, k-1, cuts) + f(k+1, j, cuts);
            mini = min(cost, mini);
        }
        
        return mini;
    }
    
     int memo(int i, int j, vector<int>& cuts, vector<vector<int>> &dp) {
        if(i > j) return 0; // base case
         if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int k=i; k<=j; k++) {
            int cost = cuts[j+1] - cuts[i-1] + memo(i, k-1, cuts, dp) + memo(k+1, j, cuts, dp);
            mini = min(cost, mini);
        }
        
        return dp[i][j] = mini;
    }
    
public:
    int minCost(int n, vector<int>& cuts) {
        
        // Recursion
        // cuts.push_back(n); // push length of the stick at the end
        // cuts.insert(cuts.begin(), 0); // push 0 at the beginning
        // sort(cuts.begin(), cuts.end());
        // return f(1, cuts.size()-2, cuts);
        
        // Memo, TC: O(m^3), SC: O(m^2 + m)
        // int m = cuts.size();
        // cuts.push_back(n); 
        // cuts.insert(cuts.begin(), 0); 
        // sort(cuts.begin(), cuts.end());
        // vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        // return memo(1, m, cuts, dp);
        
        // Tabulation, TC: O(m^3), SC: O(m^2)
        int m = cuts.size();
        cuts.push_back(n); 
        cuts.insert(cuts.begin(), 0); 
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m+2, vector<int>(m+2, 0));
        
        for(int i=m; i>=1; i--) {
            for(int j=1; j<=m; j++) {
                if(i > j) continue; //or instead of this, start j from i
                int mini = INT_MAX;
                for(int k=i; k<=j; k++) {
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(cost, mini);
                }

                dp[i][j] = mini;
            }
        }
        
        return dp[1][m];
    }
};
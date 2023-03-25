//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int idx, int W, int wt[], int val[]) {
        if(idx == 0) {
            if(wt[idx] <= W) return val[0];
            else return 0;
        }
        
        int notPick = 0 + f(idx-1, W, wt, val); // no value added
        int pick = INT_MIN;
        if(wt[idx] <= W) 
            pick = val[idx] + f(idx-1, W-wt[idx], wt, val);
            
        return max(pick, notPick);
    }
    
    int memo(int idx, int W, int wt[], int val[], vector<vector<int>> &dp) {
        if(idx == 0) {
            if(wt[idx] <= W) return val[0];
            else return 0;
        }
        
        if(dp[idx][W] != -1) return dp[idx][W];
        
        int notPick = 0 + memo(idx-1, W, wt, val, dp); // no value added
        int pick = INT_MIN;
        if(wt[idx] <= W) 
            pick = val[idx] + memo(idx-1, W-wt[idx], wt, val, dp);
            
        return dp[idx][W] = max(pick, notPick);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // Recursion, TC: O(2^n), SC: O(n)
        // return f(n-1, W, wt, val);
        
        // Memo, TC: O(n*W), SC: O(n*W + n) for 2d array and aux stack space
        // vector<vector<int>> dp(n, vector<int>(W+1, -1));
        // return memo(n-1, W, wt, val, dp);
        
        // Tabulation, TC: O(n*W), SC: O(n*W)
        // vector<vector<int>> dp(n, vector<int>(W+1, 0));
        
        // for(int j=wt[0]; j<=W; j++) {
        //     dp[0][j] = val[0];
        // }
        
        // for(int idx = 1; idx<n; idx++) {
        //     for(int j=0; j<=W; j++) {
        //         int notPick = 0 + dp[idx-1][j]; // no value added
        //         int pick = INT_MIN;
        //         if(wt[idx] <= j) 
        //             pick = val[idx] + dp[idx-1][j-wt[idx]]; 
                    
        //         dp[idx][j] = max(pick, notPick);
        //     }
        // }
        
        // return dp[n-1][W];
        
        // Space Optimisation, TC: O(n*m), SC: O(W)
        vector<int> prev(W+1, 0);
        
        for(int j=wt[0]; j<=W; j++) {
            prev[j] = val[0];
        }
        
        for(int idx = 1; idx<n; idx++) {
            vector<int> curr(W+1, 0);
            for(int j=0; j<=W; j++) {
                int notPick = 0 + prev[j]; // no value added
                int pick = INT_MIN;
                if(wt[idx] <= j) 
                    pick = val[idx] + prev[j-wt[idx]]; 
                    
                curr[j] = max(pick, notPick);
            }
            prev = curr;
        }
        
        return prev[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
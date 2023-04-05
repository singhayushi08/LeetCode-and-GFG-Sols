//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int f(int idx, int W, int val[], int wt[]) {
        if(idx == 0) {
            if(wt[0] <= W) {
                return (W/wt[0])*val[0];
            } else {
                return 0;
            }
        }
        
        int notPick = 0 + f(idx-1, W, val, wt);
        int pick = INT_MIN;
        if(wt[idx] <= W)
            pick = val[idx] + f(idx, W-wt[idx], val, wt);
            
        return max(pick, notPick);
    }
    
    int memo(int idx, int W, int val[], int wt[], vector<vector<int>> &dp) {
        if(idx == 0) {
            if(wt[0] <= W) {
                return (W/wt[0])*val[0];
            } else {
                return 0;
            }
        }
        
        if(dp[idx][W] != -1) return dp[idx][W];
        
        int notPick = 0 + memo(idx-1, W, val, wt, dp);
        int pick = INT_MIN;
        if(wt[idx] <= W)
            pick = val[idx] + memo(idx, W-wt[idx], val, wt, dp);
            
        return dp[idx][W] = max(pick, notPick);
    }
    
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // Recursion
        // return f(N-1, W, val, wt);
        
        // Memoization
        // vector<vector<int>> dp(N, vector<int>(W+1, -1));
        // return memo(N-1, W, val, wt, dp);
        
        // Tabulation
        // vector<vector<int>> dp(N, vector<int>(W+1, 0));
        // for(int w=0; w<=W; w++) {
        //     if(wt[0] <= w) dp[0][w] = (w/wt[0])*val[0];
        // }
        
        // for(int idx=1; idx<N; idx++) {
        //     for(int w=0; w<=W; w++) {
        //         int notPick = 0 + dp[idx-1][w]; 
        //         int pick = INT_MIN;
        //         if(wt[idx] <= w)
        //             pick = val[idx] + dp[idx][w-wt[idx]]; 
                    
        //         dp[idx][w] = max(pick, notPick);
        //     }
        // }
        
        // return dp[N-1][W];
        
        // Space optimised
        vector<int> prev(W+1, 0), curr(W+1, 0);
        for(int w=0; w<=W; w++) {
            if(wt[0] <= w) prev[w] = (w/wt[0])*val[0];
        }
        
        for(int idx=1; idx<N; idx++) {
            for(int w=0; w<=W; w++) {
                int notPick = 0 + prev[w]; 
                int pick = INT_MIN;
                if(wt[idx] <= w)
                    pick = val[idx] + curr[w-wt[idx]]; 
                    
                curr[w] = max(pick, notPick);
            }
            prev = curr;
        }
        
        return prev[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
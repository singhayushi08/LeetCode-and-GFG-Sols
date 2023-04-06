//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    int f(int idx, int N, int price[]) {
        if(idx == 0) {
            return N*price[0];
        }   
        
        int notPick = 0 + f(idx-1, N, price);
        int pick = INT_MIN;
        int rodLength = idx+1;
        if(rodLength <= N) 
            pick = price[idx] + f(idx, N-rodLength, price);
            
        return max(pick, notPick);
    }
    
    int memo(int idx, int N, int price[], vector<vector<int>> &dp) {
        if(idx == 0) {
            return N*price[0];
        }   
        
        if(dp[idx][N] != -1) return dp[idx][N];
        
        int notPick = 0 + memo(idx-1, N, price, dp);
        int pick = INT_MIN;
        int rodLength = idx+1;
        if(rodLength <= N) 
            pick = price[idx] + memo(idx, N-rodLength, price, dp);
            
        return dp[idx][N] = max(pick, notPick);
    }
    
    
  public:
    int cutRod(int price[], int n) {
        // cut the road into pieces such that sum of the length of pieces cut is equal to the length of original rod
        // Recursion
        // return f(n-1, n, price);
        
        // Memoization
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return memo(n-1, n, price, dp);
        
        // Tabulation
        // vector<vector<int>> dp(n, vector<int>(n+1, 0));
        // for(int N=0; N<=n; N++) {
        //     dp[0][N] = N*price[0];
        // }
        
        // for(int idx=1; idx<n; idx++) {
        //     for(int N=0; N<=n; N++) {
        //         int notPick = 0 + dp[idx-1][N];
        //         int pick = INT_MIN;
        //         int rodLength = idx+1;
        //         if(rodLength <= N) 
        //             pick = price[idx] + dp[idx][N-rodLength];
                    
        //         dp[idx][N] = max(pick, notPick);
        //     }
        // }
        
        // return dp[n-1][n];
        
        // Space Optimised
        vector<int> prev(n+1, 0), curr(n+1,0);
        for(int N=0; N<=n; N++) {
            prev[N] = N*price[0];
        }
        
        for(int idx=1; idx<n; idx++) {
            for(int N=0; N<=n; N++) {
                int notPick = 0 + prev[N];
                int pick = INT_MIN;
                int rodLength = idx+1;
                if(rodLength <= N) 
                    pick = price[idx] + curr[N-rodLength];
                    
                curr[N] = max(pick, notPick);
            }
            prev = curr;
        }
        
        return prev[n];
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
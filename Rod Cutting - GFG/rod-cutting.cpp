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
        // return f(n-1, n, price);
        
        // Memo
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return memo(n-1, n, price, dp);
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
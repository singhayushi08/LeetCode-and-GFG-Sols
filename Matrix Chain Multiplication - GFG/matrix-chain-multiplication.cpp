//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int f(int i, int j, int arr[]) {
        if(i == j) return 0;
        
        int mini = INT_MAX;
        for(int k=i; k<j; k++) {
            int steps = arr[i-1] * arr[k] * arr[j] + f(i, k,arr) + f(k+1, j, arr);
            if(steps < mini) mini = steps;
        }
        
        return mini;
    }
    
    int memo(int i, int j, int arr[], vector<vector<int>>& dp) {
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int k=i; k<j; k++) {
            int steps = arr[i-1] * arr[k] * arr[j] + memo(i, k, arr, dp) + memo(k+1, j, arr, dp);
            if(steps < mini) mini = steps;
        }
        
        return dp[i][j] = mini;
    }
    
public:
    int matrixMultiplication(int N, int arr[])
    {
        // Recursion
        // return f(1, N-1, arr);
        
        // Memoization, TC: O(N^3), SC: O(N^2 + N)
        // vector<vector<int>> dp(N, vector<int>(N,-1));
        // return memo(1, N-1, arr, dp);
        
        // Tabulation, TC: O(N^3), SC: O(N^2)
        vector<vector<int>> dp(N, vector<int>(N,0)); 
        for(int i=1; i<N; i++) dp[i][i] = 0; // base case
         
        for(int i=N-1; i>=1; i--) {
            for(int j=i+1; j<N; j++) { // i will always stay left of j
                int mini = INT_MAX;
                for(int k=i; k<j; k++) {
                    int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    if(steps < mini) mini = steps;
                }
                
                dp[i][j] = mini;
            }
        }
        
        return dp[1][N-1];
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
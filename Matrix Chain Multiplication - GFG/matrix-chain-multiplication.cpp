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
        
        vector<vector<int>> dp(N, vector<int>(N,-1));
        return memo(1, N-1, arr, dp);
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
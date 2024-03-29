//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int f(int idx, int arr[], int n, vector<int>& dp) {
        if(idx == 0) return arr[0];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int pick = arr[idx] + f(idx-2, arr, n, dp);
        int notPick = 0 + f(idx-1, arr, n, dp);
        
        return dp[idx] = max(pick, notPick);
    }
    
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Memo, TC: O(n), SC: O(n+n)
        // vector<int> dp(n, -1);
        // return f(n-1, arr, n, dp);
        
        // Tabulation, TC: O(n), SC: O(n)
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        
        for(int idx=1; idx<n; idx++) {
            int pick = arr[idx];
            if(idx >= 2) pick += dp[idx-2];
            int notPick = 0 + dp[idx-1];
            
            dp[idx] = max(pick, notPick);
        }
        
        return dp[n-1];
        
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
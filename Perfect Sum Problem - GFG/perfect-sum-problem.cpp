//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    int mod = 1e9 + 7;
    
    int f(int idx, int target, int *arr) {
        if(idx == 0) {
            if(arr[0] == 0 && target == 0) return 2;
            if(target == 0 || arr[0] == target) return 1;
            else return 0;
        }
        
        int notPick = f(idx-1, target, arr)%mod;
        int pick = 0;
        if(arr[idx] <= target) 
            pick = f(idx-1, target-arr[idx], arr)%mod;
            
        return (pick + notPick)%mod;
    }
    
    int memo(int idx, int target, int *arr, vector<vector<int>> &dp) {
        if(idx == 0) {
            if(arr[0] == 0 && target == 0) return 2;
            if(target == 0 || arr[0] == target) return 1;
            else return 0;
        }
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int notPick = memo(idx-1, target, arr, dp)%mod;
        int pick = 0;
        if(arr[idx] <= target) 
            pick = memo(idx-1, target-arr[idx], arr, dp)%mod;
            
        return dp[idx][target] = (pick + notPick)%mod;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    // Recursion, TC: O(2^n), SC: O(n)
	   // return f(n-1, sum, arr);
	   
	   // Memoization, TC: O(n*sum), SC: O(n*sum + n) for 2d array and aux stack space
	   //vector<vector<int>> dp(n, vector<int>(sum+1, -1));
	   //return memo(n-1, sum, arr, dp);
	   
	   // Tabulation, TC: O(n*sum), SC: O(n*sum)
	   //vector<vector<int>> dp(n, vector<int>(sum+1, 0));
	   //if(arr[0] == 0) {
	   //    dp[0][0] = 2;
	   //} else {
	   //    dp[0][0] = 1;
	   //}
	   
	   //if(arr[0] <= sum && arr[0] != 0) dp[0][arr[0]] = 1;
	   
	   //for(int idx=1; idx<n; idx++) {
	   //    for(int target=0; target<=sum; target++) {
	   //         int notPick = dp[idx-1][target]%mod;
    //             int pick = 0;
    //             if(arr[idx] <= target) 
    //                 pick = dp[idx-1][target-arr[idx]]%mod;
                    
    //             dp[idx][target] = (pick + notPick)%mod;
	   //    }
	   //}
	   
	   //return dp[n-1][sum];
	   
	   
	   // Space Optimisation, TC: O(n*sum), SC: O(sum)
	   vector<int> prev(sum+1, 0), curr(sum+1, 0);
	   if(arr[0] == 0) {
	       prev[0] = 2;
	   } else {
	       prev[0] = 1;
	   }
	   
	   if(arr[0] <= sum && arr[0] != 0) prev[arr[0]] = 1;
	   
	   for(int idx=1; idx<n; idx++) {
	       for(int target=0; target<=sum; target++) {
	            int notPick = prev[target]%mod;
                int pick = 0;
                if(arr[idx] <= target) 
                    pick = prev[target-arr[idx]]%mod;
                    
                curr[target] = (pick + notPick)%mod;
	       }
	       prev = curr;
	   }
	   
	   return prev[sum];
	   
	   
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
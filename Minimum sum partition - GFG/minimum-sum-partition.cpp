//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Using subset sum, TC: O(n*target), SC: O(n*target) where target is total_sum
        int total_sum = 0;
        for(int i=0; i<n; i++) {
            total_sum += arr[i];
        }
        
        vector<vector<bool>> dp(n, vector<bool>(total_sum+1, false));
        for(int i=0; i<n; i++) {
            dp[i][0] = true;
        }
        if(arr[0] <= total_sum) dp[0][arr[0]] = true;
        
        for(int i=1; i<n; i++) {
            for(int target=1; target<=total_sum; target++) {
                bool notPick = dp[i-1][target];
                bool pick = false;
                if(arr[i] <= target) {
                    pick = dp[i-1][target-arr[i]];
                }
                
                dp[i][target] = pick | notPick;
            }
        }
        
        int mini = INT_MAX;
        // iterate over last row of dp table, dp[n-1][target(i.e. col)-> 0...total_sum]
        for(int i = 0; i <= total_sum/2; i++) {
            if(dp[n-1][i] == true) {
                int s1 = i;
                int s2 = total_sum - i;
                mini = min(mini, abs(s2 - s1));
            }
        }
        
        return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends